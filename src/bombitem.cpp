#include "bombitem.h"

BombItem::BombItem()
{
}
BombItem::BombItem(int _x, int _y){
    x = _x;
    y = _y;
    image = new QPixmap(":/bomb.png");
}

onStepArgument BombItem::onStep(){

    // return instruction to increase fireSize
    return UPGRADEBOMBS;
}
onBurnArgument BombItem::onBurn(){
    return NOACTION;
}

