#pragma once

#include "KObject.h"
#include "UpdatingVector.h"
#include "KSimulationUserChangedBool.h"
#include "Timeline.h"
#include "Utilities.h"

class KSimulation
{
	std::vector<KObject> kobjects;
	std::vector<UpdatingVector> accelarationChanges;
	std::vector<UpdatingVector> velocityChanges;
	float tickLength;
	float maxSimulationDuration;
	Timeline timeline;
public:

	KSimulation();

	bool AddObject(KObject obj);
	bool AddObject(std::string cname, Point cpos); 
	inline bool AddObjectInline(KObject obj);
	bool RemoveObject(std::string cname); 

	bool AddAcceleration(UpdatingVector obj);
	bool AddAcceleration(std::string ctarget, float ctimestamp, Point cdir, bool creplace); 
	bool RemoveAcceleration(std::string ctarget, float ctimestamp);

	bool AddVelocity(UpdatingVector obj);
	bool AddVelocity(std::string ctarget, float ctimestamp, Point cdir, bool creplace); 
	bool RemoveVelocity(std::string ctarget, float ctimestamp);

	inline bool AddObjectAccOrVel(std::vector<UpdatingVector>& arr, UpdatingVector obj);
	inline bool RemoveObjectAccOrVel(std::vector<UpdatingVector>& arr, std::string ctarget, float ctimestamp);

	void FillTickUpdateValues(std::vector<KSimulationUserChangedBool> &arr);
	float InterpolateTimestamp(float timestamp);
	void CheckForUserDefinedAccORVel(KObject& x, const std::vector<UpdatingVector>& updatingVector, std::string type);

	void PrintEntireTimeline(); 

	bool Start(float tickLength, float maxSimulationDuration);
};

