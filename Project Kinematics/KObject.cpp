#include "KObject.h"

int KObject::kobject_count = 0;

KObject::KObject(std::string cname, Point cpos) : Object(cname,cpos.x,cpos.y,cpos.z)
{
	totalDistanceTraveled = 0;
	kobject_count++;
	this->tickLength = 0.001f;
}

KObject::~KObject()
{
	kobject_count--;
}

void KObject::SetTickLength(float tickLength)
{
	this->tickLength = tickLength;
}

float KObject::GetTickLength() const
{
	return this->tickLength;
}

void KObject::SetAccelarationVector(Point accv)
{
	this->accelarationVector.x = accv.x;
	this->accelarationVector.y = accv.y;
	this->accelarationVector.z = accv.z;
}

Point KObject::GetAccelarationVector() const
{
	return accelarationVector;
}

void KObject::ChangeAccelarationVector(Point accv)
{
	this->accelarationVector.x += accv.x;
	this->accelarationVector.y += accv.y;
	this->accelarationVector.z += accv.z;
}

void KObject::SetVelocityVector(Point velv)
{
	this->velocityVector.x = velv.x;
	this->velocityVector.y = velv.y;
	this->velocityVector.z = velv.z;
}

Point KObject::GetVelocityVector() const
{
	return velocityVector;
}

void KObject::ChangeVelocityVector(Point velv)
{
	this->velocityVector.x += velv.x;
	this->velocityVector.y += velv.y;
	this->velocityVector.z += velv.z;
}

void KObject::Update()
{
	// v=s/t
	// a=v/t -> v=at
	// v = v0 + at
	float vdx = accelarationVector.x * tickLength;
	float vdy = accelarationVector.y * tickLength;
	float vdz = accelarationVector.z * tickLength;

	velocityVector.x += vdx;
	velocityVector.y += vdy;
	velocityVector.z += vdz;

	float dx = tickLength * velocityVector.x;
	float dy = tickLength * velocityVector.y;
	float dz = tickLength * velocityVector.z;

	Point temp(dx, dy, dz);
	totalDistanceTraveled += temp.DistanceFromOrigin();

	this->pos.x += dx;
	this->pos.y += dy;
	this->pos.z += dz;
}
