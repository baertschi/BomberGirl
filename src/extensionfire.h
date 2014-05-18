#ifndef EXTENSIONFIRE_H
#define EXTENSIONFIRE_H
#include "fire.h"
#include "mytimer.h"

class MyTimer;

class ExtensionFire : public Fire
{
public:
    ExtensionFire();
    ExtensionFire(int _x, int _y, MyTimer* timer, orientation ori);

    onStepArgument onStep();
    onBurnArgument onBurn();
};

#endif // EXTENSIONFIRE_H
