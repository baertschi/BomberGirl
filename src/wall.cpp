#include "wall.h"
#include <iostream>
Wall::Wall(){

}

Wall::Wall(int _x, int _y){
    x = _x;
    y = _y;
    image = wallImage;
    //std::cout << "wall " << x << "  " << y << "\n";
}
onBurnArgument Wall::onBurn(){

    // return wall
    return HARDBLOCK;
}
onStepArgument Wall::onStep(){

    // return wall
    return NOENTRY;
}
