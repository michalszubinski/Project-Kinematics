#pragma once
#include "TimelineTimestampData.h"

class TimelineTimestamp
{
	TimelineTimestampData data;
public:

	TimelineTimestamp(float tick, Point loc, Point vel, Point acc);
	TimelineTimestamp(TimelineTimestampData data);

	TimelineTimestampData GetData() const;
	std::string GetDataAsText() const;
	//void SetData(TimelineTimestampData data);
};

/* TIMELINE -> TIMELINE OF ONE OBJECT -> TIMESTAMP OF ONE OBJECT -> [LOCATION, VELOCITY (+VECTOR ANGLE), ACCELERATION (+VECTOR ANGLE)]*/
