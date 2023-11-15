#include "Point.h"

Point::Point() : x(0), y(0), z(0)
{
}

Point::Point(float cx) : x(cx), y(0), z(0)
{
}

Point::Point(float cx, float cy) : x(cx), y(cy), z(0)
{
}

Point::Point(float cx, float cy, float cz) : x(cx),y(cy),z(cz)
{
}

float Point::DistanceFromOrigin()
{
    return sqrt((x*x)+ (y*y)+ (z*z));
}

std::string Point::CoordinatesAsText() const
{
    std::string temp("");
    const std::string separator = ", ";
    temp = std::to_string(x)+separator + std::to_string(y) + separator + std::to_string(z);

    return temp;
}
