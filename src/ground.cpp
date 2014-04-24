#include "ground.h"
#include <iostream>

Ground::Ground()
{

}
Ground::Ground(int _x, int _y){
    x = _x;
    y = _y;
    image = groundImage;
}
Ground::Ground(int _x, int _y, BombItem *_theBombItem){
    Ground(_x, _y);
    itemElement = _theBombItem;
    brickElement = new Brick(_x, _y);

}

Ground::Ground(int _x, int _y, FlashItem *_theFlashItem){
    Ground(_x, _y);
    itemElement = _theFlashItem;
    brickElement = new Brick(_x, _y);

}

Ground::Ground(int _x, int _y, Brick *_theBrick){
    Ground(_x, _y);
    brickElement = _theBrick;

}

onStepArgument Ground::onStep(){
    // first execute onStep Method of fieldContents (highest priority first)

    return ENTRY;
}
onBurnArgument Ground::onBurn(){
    return NOACTION;
}


void placeBomb(){

}
