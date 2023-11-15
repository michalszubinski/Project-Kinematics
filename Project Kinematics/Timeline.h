#pragma once
#include "Libraries.h"
#include "TimelineObject.h"
#include "KObject.h"
#include "TimelineObjectTable.h"

class Timeline
{
	std::vector<TimelineObject> objectVector;
	std::vector<TimelineObjectTable> objectTable;
public:

	void BuildObjectTable(const std::vector<KObject> &arr);
	void AddTimestamp(std::string name, TimelineTimestampData data); // AddTimestamp could use std::move with unique_ptr
	void AddTimestamp(int id, TimelineTimestampData data);
	inline void AddTimestampInline(int& id, TimelineTimestampData &data);
	int searchObjectTableForID(std::string name);
	void PrintAllTimestamps();
};

/* TIMELINE -> TIMELINE OF ONE OBJECT -> TIMESTAMP OF ONE OBJECT -> [LOCATION, VELOCITY (+VECTOR ANGLE), ACCELERATION (+VECTOR ANGLE)]*/