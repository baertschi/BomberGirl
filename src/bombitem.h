#ifndef BOMBITEM_H
#define BOMBITEM_H
#include "item.h"
class BombItem : public Item
{
public:
    BombItem();
    enum onStepReturnArgument onStep();
};

#endif // BOMBITEM_H
