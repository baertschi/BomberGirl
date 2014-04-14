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
onStepArgument Ground::onStep(){
    return ENTRY;
}
onBurnArgument Ground::onBurn(){
    return NOACTION;
}
void placeBomb(){

}
