#include "TimelineTimestampData.h"

TimelineTimestampData::TimelineTimestampData(float tick, Point loc, Point vel, Point acc) : tick(tick), loc(loc), vel(vel), acc(acc)
{
}

void TimelineTimestampData::CalculateAngles()
{
	vel_angle.Calculate(vel);
	acc_angle.Calculate(acc);
}
