#include "wall.h"
#include <iostream>
Wall::Wall(){

}

Wall::Wall(int _x, int _y){
    x = _x;
    y = _y;
   // image.load("wall.jpg");     // wall.jpg does not exist, this may cause errors
    std::cout << "wall " << x << "  " << y << "\n";
}
onBurnArgument Wall::onBurn(){

    // return wall
    return HARDBLOCK;
}
onStepArgument Wall::onStep(){

    // return wall
    return NOENTRY;
}
