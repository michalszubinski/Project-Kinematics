#include "Angle.h"

void Angle::Calculate(Point loc)
{
	float dist = loc.DistanceFromOrigin();
	if (dist == 0)
	{
		x = 0;
		y = 0;
		z = 0;

		return;
	}
	x = asin(loc.x/dist)*360/(2*M_PI);
	y = asin(loc.y/dist)*360/(2 * M_PI);
	z = asin(loc.z/dist)*360/(2 * M_PI);
}
