#include "bomb.h"

Bomb::Bomb(int _fireSize, int *_pBombCounter)
{
    fireSize = _fireSize;
    pBombCounter = _pBombCounter;
    image = bombImage;
}

onStepArgument Bomb::onStep(){
    return NOENTRY;
}

onBurnArgument Bomb::onBurn(){
    // TODO: trigger bomb immediately!
    return TRIGGER;
}
