#include "corefire.h"

CoreFire::CoreFire()
{
}
CoreFire::CoreFire(int _x, int _y)
{
    x = _x;
    y = _y;
    image = coreFireImage;
    std::cout << "corefire created"<< std::endl;
}
onBurnArgument CoreFire::onBurn(){
    return NOACTION;
}
onStepArgument CoreFire::onStep(){
    return DIE;
}
