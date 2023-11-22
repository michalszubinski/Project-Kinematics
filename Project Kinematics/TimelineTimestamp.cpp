#include "TimelineTimestamp.h"

TimelineTimestamp::TimelineTimestamp(float tick, Point loc, Point vel, Point acc) 
{
	this->data.tick = tick;
	this->data.loc = loc;
	this->data.vel = vel;
	this->data.acc = acc;

	this->data.CalculateAngles();
	//this->data.vel_angle.Calculate(vel);
	//this->data.acc_angle.Calculate(acc);
}

TimelineTimestamp::TimelineTimestamp(TimelineTimestampData data) : data(data)
{
	this->data.CalculateAngles();
	//this->data.vel_angle.Calculate(data.vel);
	//this->data.acc_angle.Calculate(data.acc);
}

TimelineTimestampData TimelineTimestamp::GetData() const
{
	return data;
}

std::string TimelineTimestamp::GetDataAsText() const
{
	std::string temp;
	const std::string separator = ", ";

	temp = std::to_string(data.tick) + separator + "POS: " + 
		data.loc.CoordinatesAsText() + separator + "VEL: " +
		data.vel.CoordinatesAsText() + separator + "ACC: " +
		data.acc.CoordinatesAsText() + separator + "VEL_ANG: " +
		data.vel_angle.CoordinatesAsText() + separator + "ACC_ANG: " +
		data.acc_angle.CoordinatesAsText() + "\n";

	return temp;
}
