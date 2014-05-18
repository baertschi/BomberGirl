#ifndef BOMB_H
#define BOMB_H
#include <vector>
#include "mytimer.h"
//#include "corefire.h"
//#include "extensionfire.h"
//#include "endfire.h"

typedef std::vector< std::vector< Field* > > mapMatrix;

class MyTimer;
class Bomb : public Elapsing
{
private:

    int *pBombCounter;
    mapMatrix *map;
public:
    Bomb(int _x, int _y, int _fireSize, int *_pBombCounter, MyTimer* timer, mapMatrix *_map);
    onStepArgument onStep();
    onBurnArgument onBurn();
    int fireSize;

};

#endif // BOMB_H
