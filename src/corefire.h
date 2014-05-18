#ifndef COREFIRE_H
#define COREFIRE_H
#include "fire.h"
#include "mytimer.h"
#include <iostream>
class MyTimer;


class CoreFire : public Fire
{
public:
    CoreFire();
    CoreFire(int _x, int _y, MyTimer* timer);

    onStepArgument onStep();
    onBurnArgument onBurn();
};

#endif // COREFIRE_H
