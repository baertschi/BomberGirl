#include "brick.h"

Brick::Brick()
{
}
Brick::Brick(int _x, int _y){
    x = _x;
    y = _y;
    image = new QPixmap(":/brick.png");
}
onBurnArgument Brick::onBurn(){
    return BLOCK;
}
onStepArgument Brick::onStep(){
    return NOENTRY;
}

