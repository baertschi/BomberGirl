#ifndef COREFIRE_H
#define COREFIRE_H
#include "fire.h"
#include <iostream>

class CoreFire : public Fire
{
public:
    CoreFire();
    CoreFire(int _x, int _y);

    onStepArgument onStep();
    onBurnArgument onBurn();
};

#endif // COREFIRE_H
