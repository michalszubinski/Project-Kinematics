#pragma once
#include "Point.h"
class UpdatingVector
{
	Point dir;
	std::string target;
	float timestamp;
	float correctedtimestamp;
	bool replace;

public:
	UpdatingVector(std::string ctarget, float ctimestamp, Point cdir);
	UpdatingVector(std::string ctarget, float ctimestamp, Point cdir, bool creplace);

	Point GetDir() const;
	void SetDir(Point dir);

	std::string GetTarget() const;
	void SetTarget(std::string target);

	float GetTimestamp() const;
	void SetTimestamp(float timestamp);

	float GetCorrectedTimestamp() const;
	void SetCorrectedTimestamp(float timestamp);

	bool CheckIfShouldReplace() const;
};

