#include "TimelineObject.h"

TimelineObject::TimelineObject(std::string name) : name(name)
{
}

void TimelineObject::AddTimestamp(TimelineTimestampData data)
{
	TimelineTimestamp temp(data);
	timestampVector.push_back(temp);
}

std::vector<std::string> TimelineObject::GetDataAsText()
{
	std::vector<std::string> temp;
	temp.push_back("DATA OF THE '" + this->name + "' OBJECT\n");

	for (auto& x : timestampVector) {
		temp.push_back(x.GetDataAsText());
	}
	temp.push_back("\n\n");

	return temp;
}

