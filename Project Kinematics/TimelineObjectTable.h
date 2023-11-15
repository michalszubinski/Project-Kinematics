#pragma once
#include <string>

struct TimelineObjectTable {
	int id=0;
	std::string name;

	TimelineObjectTable() = default;
	TimelineObjectTable(int id, std::string name) : id(id), name(name) {};
};