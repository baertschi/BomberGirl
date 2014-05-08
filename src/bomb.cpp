#include "bomb.h"
#include "mainwindow.h"

Bomb::Bomb(int _fireSize, int *_pBombCounter, MyTimer* timer)
{
    fireSize = _fireSize;
    pBombCounter = _pBombCounter;
    image = bombImage;
    timer->attach(this);
}

onStepArgument Bomb::onStep(){
    return NOENTRY;
}

onBurnArgument Bomb::onBurn(){
    // TODO: trigger bomb immediately!
    *pBombCounter = *pBombCounter - 1;
    std::cout << "\nonburn\n";
    return TRIGGER;
}
