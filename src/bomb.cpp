#include "bomb.h"
#include "mainwindow.h"

Bomb::Bomb(int _fireSize, int *_pBombCounter, MyTimer* timer, mapMatrix &_map)
{
    fireSize = _fireSize;
    pBombCounter = _pBombCounter;
    image = bombImage;
    map = _map;
    timer->attach(this);

}

onStepArgument Bomb::onStep(){
    return NOENTRY;
}

onBurnArgument Bomb::onBurn(){
    // TODO: trigger bomb immediately!
    *pBombCounter = *pBombCounter - 1;
    static_cast<Ground *>(map[x][y])->bombElement = NULL;

    std::cout << "\nonburn\n";
    return TRIGGER;
}
