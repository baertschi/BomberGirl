#include "bomb.h"
#include "mainwindow.h"

Bomb::Bomb(int _fireSize, int *_pBombCounter, MyTimer* timer, const mapMatrix &_map)
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
    std::cout << " onburn vor corefire"<< std::endl;
    *pBombCounter = *pBombCounter - 1;
    std::cout << " onburn vor corefire"<< std::endl;
    static_cast<Ground *>(map[x][y])->fireElement = new CoreFire(x, y);
    std::cout << "\n onburn\n"<< std::endl;
    //static_cast<Ground *>(map[x][y])->bombElement = NULL;

    std::cout << " onburn vor corefire"<< std::endl;

    return TRIGGER;
}
