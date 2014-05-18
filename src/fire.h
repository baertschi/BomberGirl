#ifndef FIRE_H
#define FIRE_H
#include "elapsing.h"

enum orientation {
    L,
    R,
    U,
    D
};

class Fire : public Elapsing
{
public:
    Fire();
};

#endif // FIRE_H
