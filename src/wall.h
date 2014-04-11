#ifndef WALL_H
#define WALL_H
#include "field.h"

class Wall : public Field
{
public:
    Wall();
    Wall(int _x, int _y);
    onBurnArgument onBurn();
    onStepArgument onStep();
};

#endif // WALL_H
