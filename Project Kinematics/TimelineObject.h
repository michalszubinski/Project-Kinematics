#pragma once
#include "TimelineTimestamp.h"

class TimelineObject
{
	std::vector<TimelineTimestamp> timestampVector;
	std::string name;
public:

	TimelineObject() = default;
	TimelineObject(std::string name);

	void AddTimestamp(TimelineTimestampData data);
	std::vector<std::string> GetDataAsText();
};

/* TIMELINE -> TIMELINE OF ONE OBJECT -> TIMESTAMP OF ONE OBJECT -> [LOCATION, VELOCITY (+VECTOR ANGLE), ACCELERATION (+VECTOR ANGLE)]*/
