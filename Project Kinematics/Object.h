#pragma once

#include "Point.h"

class Object
{
	std::string name;
	static int object_count;
protected:
	Point pos;
public:

	Object(std::string cname);
	Object(std::string cname, float cx);
	Object(std::string cname, float cx, float cy);
	Object(std::string cname, float cx, float cy, float cz);
	~Object();

	void ChangePos(float x, float y, float z);
	void SetPos(float x, float y, float z);
	void SetPos(Point pos);
	Point GetPos() const;

	std::string GetName() const;
	void SetName(std::string name);
};

