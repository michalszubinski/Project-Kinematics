#include "Object.h"

int Object::object_count = 0;

Object::Object(std::string cname) : name(cname), pos()
{
	object_count++;
}

Object::Object(std::string cname, float cx) : name(cname), pos(cx)
{
	object_count++;
}

Object::Object(std::string cname, float cx, float cy) : name(cname), pos(cx,cy)
{
	object_count++;
}

Object::Object(std::string cname, float cx, float cy, float cz) : name(cname), pos(cx,cy,cz)
{
	object_count++;
}

Object::~Object()
{
	object_count--;
}

void Object::SetPos(float x, float y, float z)
{
	this->pos.x = x;
	this->pos.y = y;
	this->pos.z = z;
}

void Object::ChangePos(float x, float y, float z)
{
	this->pos.x += x;
	this->pos.y += y;
	this->pos.z += z;
}

void Object::SetPos(Point pos)
{
	this->pos = pos;
}

Point Object::GetPos() const
{
	return pos;
}

void Object::SetName(std::string name)
{
	this->name = name;
}


std::string Object::GetName() const
{
	return name;
}
