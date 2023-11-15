#include "Timeline.h"

void Timeline::BuildObjectTable(const std::vector<KObject>& arr)
{
	int i = 0;
	TimelineObjectTable temp;

	for (const auto& x : arr) {
		temp.id = i;
		temp.name = x.GetName();
		objectTable.push_back(temp);
		objectVector.push_back(TimelineObject(temp.name));
		++i;
	}
}

void Timeline::AddTimestamp(std::string name, TimelineTimestampData data)
{
	int objTable_id = searchObjectTableForID(name);
	AddTimestampInline(objTable_id, data);
}

void Timeline::AddTimestamp(int id, TimelineTimestampData data)
{
	AddTimestampInline(id, data);
}

inline void Timeline::AddTimestampInline(int& id, TimelineTimestampData& data)
{
	objectVector[id].AddTimestamp(data);
}

int Timeline::searchObjectTableForID(std::string name)
{
	for (const auto& x : objectTable) {
		if (name == x.name) return x.id;
	}

	return -1;
}

void Timeline::PrintAllTimestamps()
{
	std::vector<std::string> temp;

	for (auto& x : objectVector) {
		temp = x.GetDataAsText();
		for (auto& y : temp) {
			std::cout << y;
		}
	}
}
