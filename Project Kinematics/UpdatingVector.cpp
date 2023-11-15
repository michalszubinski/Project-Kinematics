#include "UpdatingVector.h"

UpdatingVector::UpdatingVector(std::string ctarget, float ctimestamp, Point cdir) : dir(cdir), target(ctarget), timestamp(ctimestamp)
{
}

UpdatingVector::UpdatingVector(std::string ctarget, float ctimestamp, Point cdir, bool creplace) : dir(cdir), target(ctarget), timestamp(ctimestamp), replace(creplace)
{
}

Point UpdatingVector::GetDir() const
{
    return dir;
}

void UpdatingVector::SetDir(Point dir)
{
    this->dir = dir;
}

std::string UpdatingVector::GetTarget() const
{
    return target;
}

void UpdatingVector::SetTarget(std::string target)
{
    this->target = target;
}

float UpdatingVector::GetTimestamp() const
{
    return timestamp;
}

void UpdatingVector::SetTimestamp(float timestamp)
{
    this->timestamp = timestamp;
}

float UpdatingVector::GetCorrectedTimestamp() const
{
    return correctedtimestamp;
}

void UpdatingVector::SetCorrectedTimestamp(float timestamp)
{
    this->correctedtimestamp = timestamp;
}

bool UpdatingVector::CheckIfShouldReplace() const
{
    return replace;
}
