#pragma once
#include "Libraries.h"

struct Point
{
	float x;
	float y;
	float z;

	Point();
	Point(float cx);
	Point(float cx, float cy);
	Point(float cx, float cy, float cz);
	
	float DistanceFromOrigin();
	std::string CoordinatesAsText() const;
};

