#ifndef BRICK_H
#define BRICK_H
#include "fieldcontent.h"

class Brick : public FieldContent
{
public:
    Brick();
    Brick(int _x, int _y);
    onBurnArgument onBurn();
    onStepArgument onStep();

};

#endif // BRICK_H
