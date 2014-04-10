#include "bombitem.h"

BombItem::BombItem()
{
}

enum onStepReturnArgument BombItem::onStep(){
    // return instruction to increase fireSize
    return DIE;
}

