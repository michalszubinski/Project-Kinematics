#include "KSimulation.h"

KSimulation::KSimulation()
{
	this->tickLength = 0.1;
	this->maxSimulationDuration = 10;
}

bool KSimulation::AddObject(KObject obj)
{
	if (AddObjectInline(obj)) return true;
	return false;
}

bool KSimulation::AddObject(std::string cname, Point cpos)
{
	KObject obj(cname, cpos);
	if (AddObjectInline(obj)) return true;
	return false;
}

inline bool KSimulation::AddObjectInline(KObject obj)
{
	for (auto& x : kobjects) {
		if (x.GetName() == obj.GetName()) return false;
	}

	kobjects.push_back(obj);

	return true;
}

bool KSimulation::RemoveObject(std::string cname)
{
	unsigned int i = 0;
	for (auto& x : kobjects) {
		if (x.GetName() == cname) {
			kobjects.erase(kobjects.begin() + i);
			return true;
		} 
		++i;
	}

	return false;
}

bool KSimulation::AddAcceleration(UpdatingVector obj)
{
	if (AddObjectAccOrVel(this->accelarationChanges,obj)) return true;
	return false;
}

bool KSimulation::AddAcceleration(std::string ctarget, float ctimestamp, Point cdir, bool creplace)
{
	UpdatingVector obj(ctarget, ctimestamp, cdir, creplace);
	if (AddObjectAccOrVel(this->accelarationChanges, obj)) return true;
	return false;
}

bool KSimulation::RemoveAcceleration(std::string ctarget, float ctimestamp)
{
	if (RemoveObjectAccOrVel(this->accelarationChanges, ctarget, ctimestamp)) return true;
	return false;
}

bool KSimulation::AddVelocity(UpdatingVector obj)
{
	if (AddObjectAccOrVel(this->velocityChanges, obj)) return true;
	return false;
}

bool KSimulation::AddVelocity(std::string ctarget, float ctimestamp, Point cdir, bool creplace = 0)
{
	UpdatingVector obj(ctarget, ctimestamp, cdir, creplace);
	if (AddObjectAccOrVel(this->velocityChanges, obj)) return true;
	return false;
}

bool KSimulation::RemoveVelocity(std::string ctarget, float ctimestamp)
{
	if (RemoveObjectAccOrVel(this->velocityChanges, ctarget, ctimestamp)) return true;
	return false;
}

inline bool KSimulation::AddObjectAccOrVel(std::vector<UpdatingVector>& arr, UpdatingVector obj)
{
	for (auto& x : arr) {
		if (x.GetTarget() == obj.GetTarget() && x.GetTimestamp() == obj.GetTimestamp()) return false;
	}

	arr.push_back(obj);

	return true;
}

inline bool KSimulation::RemoveObjectAccOrVel(std::vector<UpdatingVector>& arr, std::string ctarget, float ctimestamp)
{
	unsigned int i = 0;
	for (auto& x : arr) {
		if (x.GetTarget() == ctarget && x.GetTimestamp() == ctimestamp) {
			arr.erase(arr.begin() + i);
			return true;
		}
		++i;
	}

	return false;
}

void KSimulation::FillTickUpdateValues(std::deque<KSimulationUserChangedBool>& arr)
{
	KSimulationUserChangedBool temp;
	float inter(0);

	for (auto& x : velocityChanges) {
		temp.vel = true;
		temp.acc = false;

		inter = InterpolateTimestamp(x.GetTimestamp());
		x.SetCorrectedTimestamp(inter);// CALCULATE CORRECTTIMESTAMP
		temp.tick = inter; // CORRECT temp.tick TO THIS TIMESTAMP

		arr.push_back(temp);
		
	}

	for (auto& x : accelarationChanges) {
		temp.tick = x.GetTimestamp();
		temp.vel = false;
		temp.acc = true;

		inter = InterpolateTimestamp(x.GetTimestamp());
		x.SetCorrectedTimestamp(inter);// CALCULATE CORRECTTIMESTAMP
		temp.tick = inter; // CORRECT temp.tick TO THIS TIMESTAMP

		arr.push_back(temp);
	}

	Utilities::VectorKSimulationUserChangedBoolSort(arr); // SORT ARRAY

	// AGGREGATE ARRAY [JOIN TIMESTAMPS WITH DIFFERENT FLAGS]
	std::vector<int> idsToRemove;

	int i = 0;
	for (const auto& x : arr) {
		if (x.del) idsToRemove.push_back(i);
		++i;
	}

	std::reverse(idsToRemove.begin(), idsToRemove.end());

	std::vector<int>::iterator j = idsToRemove.end();
	i = 0;
	while (j != idsToRemove.begin()) // TO DO
	{
		--j;
		arr.erase(arr.begin() + idsToRemove[i]);
		++i;
	}
}

float KSimulation::InterpolateTimestamp(float timestamp)
{
	float proportion = timestamp / tickLength;
	if (Utilities::IsInteger(proportion))
		return timestamp;


	if (proportion - std::floor(proportion) > 0.5) {
		return static_cast<float>(std::floor(proportion))*tickLength;
	}
	else
	{
		return ( static_cast<float>(std::floor(proportion)) + 1) * tickLength;
	}

}

void KSimulation::CheckForUserDefinedAccORVel(KObject& x, const std::vector<UpdatingVector> &updatingVector, std::string type)
{



	for (const auto& change : updatingVector) {
		if (change.GetTarget() == x.GetName()) {
			if (change.CheckIfShouldReplace()) {
				if(type=="acc") x.SetAccelarationVector(change.GetDir());
				else if (type == "vel") x.SetVelocityVector(change.GetDir());
			}
			else {
				if (type == "acc") x.ChangeAccelarationVector(change.GetDir());
				else if (type == "vel") x.ChangeVelocityVector(change.GetDir());
			}
		}
	}
}

void KSimulation::PrintEntireTimeline()
{
	timeline.PrintAllTimestamps();
}

bool KSimulation::Start(float tickLength, float maxSimulationDuration)
{
	bool flag_initbadvalue = 0;
	std::deque<KSimulationUserChangedBool> tickUpdateValues; 

	if (tickLength <= 0 || maxSimulationDuration <= 0) flag_initbadvalue = 1;
	if (tickLength >= maxSimulationDuration) flag_initbadvalue = 1;
	if (kobjects.size() == 0) flag_initbadvalue = 1;

	if (flag_initbadvalue == 1)
		return false;

	// INIT TIMELINE
	timeline.BuildObjectTable(kobjects);


	FillTickUpdateValues(tickUpdateValues);
	float currentTick = 0;

	bool acc_changeflag = 0;
	bool vel_changeflag = 0;
	bool any_changeflag = 0;

	for (auto& x : kobjects) {
		x.SetTickLength(tickLength);
	}

	int timestamp_num(0);

	while (currentTick < maxSimulationDuration)
	{
		acc_changeflag = 0;
		vel_changeflag = 0;
		any_changeflag = 0;

		for (const auto& simEvent : tickUpdateValues) {
			if (simEvent.tick == currentTick)
			{
				if (simEvent.acc) acc_changeflag = 1;
				if (simEvent.vel) vel_changeflag = 1;
				any_changeflag = 1;
			}
		}

		for (auto& x : kobjects) {

			if (acc_changeflag) CheckForUserDefinedAccORVel(x, accelarationChanges,"acc");
			if (vel_changeflag) CheckForUserDefinedAccORVel(x, velocityChanges, "vel");
			if (any_changeflag) tickUpdateValues.pop_front(); // delete this tickUpdateValue - no longer used
			// possible bugs if container not sorted (it shouldn't be)

			timeline.AddTimestamp(x.GetName(), TimelineTimestampData(currentTick, x.GetPos(), x.GetVelocityVector(), x.GetAccelarationVector()));
			// TimelineTimestampData(float tick, Point loc, Point vel, Point acc);

			x.Update();
		}


		++timestamp_num;
		currentTick = tickLength * static_cast<float>(timestamp_num);
	}


	return true;
}
