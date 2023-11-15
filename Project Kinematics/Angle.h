#pragma once
#include "Point.h"
struct Angle : public Point
{
	void Calculate(Point loc); // TO DO

	float DistanceFromOrigin() = delete;
};

