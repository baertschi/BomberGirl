#ifndef BOMBITEM_H
#define BOMBITEM_H
#include "item.h"
class BombItem : public Item
{
public:
    BombItem();
    BombItem(int _x, int _y);
    onStepArgument onStep();
    onBurnArgument onBurn();
};

#endif // BOMBITEM_H
