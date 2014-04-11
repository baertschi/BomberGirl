#include "ground.h"
#include <iostream>

Ground::Ground()
{
}
Ground::Ground(int _x, int _y){
    x = _x;
    y = _y;
   // image.load("ground.jpg");
    std::cout << "ground-field " << x << "  " << y << "\n";
}
onStepArgument Ground::onStep(){
    return ENTRY;
}
onBurnArgument Ground::onBurn(){
    return NOACTION;
}
void placeBomb(){

}
