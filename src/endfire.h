#ifndef ENDFIRE_H
#define ENDFIRE_H
#include "fire.h"
#include "mytimer.h"

class MyTimer;

class EndFire : public Fire
{
public:
    EndFire();
    EndFire(int _x, int _y, MyTimer* timer, orientation ori);

    onStepArgument onStep();
    onBurnArgument onBurn();
};

#endif // ENDFIRE_H
