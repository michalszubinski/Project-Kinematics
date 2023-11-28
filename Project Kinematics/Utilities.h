#pragma once
#include "Libraries.h"
#include "KSimulationUserChangedBool.h"

class Utilities
{
public:
	static bool IsInteger(float num);
	static void VectorKSimulationUserChangedBoolSort(std::vector<KSimulationUserChangedBool>& arr);
	static void VectorKSimulationUserChangedBoolSort(std::deque<KSimulationUserChangedBool>& arr);
};

