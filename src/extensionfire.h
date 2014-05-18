#ifndef EXTENSIONFIRE_H
#define EXTENSIONFIRE_H
#include "fire.h"
class ExtensionFire : public Fire
{
public:
    ExtensionFire();
    ExtensionFire(int _x, int _y);

    onStepArgument onStep();
    onBurnArgument onBurn();
};

#endif // EXTENSIONFIRE_H
