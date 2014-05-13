#ifndef COREFIRE_H
#define COREFIRE_H
#include "fire.h"
class CoreFire : public Fire
{
public:
    CoreFire();
    CoreFire(int _x, int _y);

    onStepArgument onStep();
    onBurnArgument onBurn();
};

#endif // COREFIRE_H
