#include "KSimulationUserChangedBool.h"

KSimulationUserChangedBool& KSimulationUserChangedBool::operator=(const KSimulationUserChangedBool& obj)
{
    if (this == &obj) {
        return *this;
    }

    this->tick = obj.tick;
    this->acc = obj.acc;
    this->vel = obj.vel;
    this->del = obj.del;

    return *this;
}
