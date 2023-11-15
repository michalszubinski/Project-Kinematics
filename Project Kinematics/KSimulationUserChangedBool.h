#pragma once

struct KSimulationUserChangedBool {
	float tick = 0;
	bool acc = 0;
	bool vel = 0;
	bool del = 0;

	KSimulationUserChangedBool& operator=(const KSimulationUserChangedBool& obj);
};