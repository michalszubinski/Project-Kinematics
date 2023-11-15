#pragma once
#include "Point.h"
#include "Angle.h"

struct TimelineTimestampData {
	float tick = 0;
	Point loc;
	Point vel;
	Angle vel_angle;
	Point acc;
	Angle acc_angle;

	TimelineTimestampData() = default;
	TimelineTimestampData(float tick, Point loc, Point vel, Point acc);
	void CalculateAngles();
};