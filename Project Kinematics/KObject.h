#pragma once
#include "Object.h"

class KObject : public Object
{
	Point accelarationVector;
	Point velocityVector;
	float totalDistanceTraveled;
	float tickLength;
	static int kobject_count;

public:

	KObject(std::string cname, Point cpos);
	~KObject();

	void SetTickLength(float tickLength);
	float GetTickLength() const;

	void SetAccelarationVector(Point accv);
	Point GetAccelarationVector() const;
	void ChangeAccelarationVector(Point accv);

	void SetVelocityVector(Point velv);
	Point GetVelocityVector() const;
	void ChangeVelocityVector(Point velv);

	void Update();
};

