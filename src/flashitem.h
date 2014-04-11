#ifndef FLASHITEM_H
#define FLASHITEM_H
#include "item.h"
class FlashItem : public Item
{
public:
    FlashItem();
    FlashItem(int _x, int _y);
    onStepArgument onStep();
    onBurnArgument onBurn();
};

#endif // FLASHITEM_H
