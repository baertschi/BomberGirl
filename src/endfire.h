#ifndef ENDFIRE_H
#define ENDFIRE_H
#include "fire.h"

class EndFire : public Fire
{
public:
    EndFire();
    EndFire(int _x, int _y, orientation ori);

    onStepArgument onStep();
    onBurnArgument onBurn();
};

#endif // ENDFIRE_H
