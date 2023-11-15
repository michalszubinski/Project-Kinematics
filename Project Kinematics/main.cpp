#include "Libraries.h"
#include "KSimulation.h"

int main()
{

	KSimulation sim;

	KObject obj("Test",Point(0,0,0));

	sim.AddObject(obj);
	sim.AddVelocity("Test", 0, Point(0, 0, 20), 1);
	sim.AddAcceleration("Test", 0, Point(0, 0, -10), 1);

	sim.Start(1,15.0);
	sim.PrintEntireTimeline();

	return 0;
}

