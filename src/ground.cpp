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
Ground::Ground(int _x, int _y, BombItem *theBombItem){
    Ground(_x, _y);
    fieldContents[0] = theBombItem;
    fieldContents[2] = new Brick(_x, _y);
}

Ground::Ground(int _x, int _y, FlashItem *theFlashItem){
    Ground(_x, _y);
    fieldContents[1] = theFlashItem;
    fieldContents[2] = new Brick(_x, _y);
}

Ground::Ground(int _x, int _y, Brick *theBrick){
    Ground(_x, _y);
    fieldContents[2] = theBrick;
}

onStepArgument Ground::onStep(){
    return ENTRY;
}
onBurnArgument Ground::onBurn(){
    return NOACTION;
}
void placeBomb(){

}
