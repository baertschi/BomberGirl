#ifndef BOMB_H
#define BOMB_H
#include <vector>
#include "elapsing.h"
#include "mytimer.h"
#include "corefire.h"
#include "extensionfire.h"
#include "endfire.h"

typedef std::vector< std::vector< Field* > > mapMatrix;


class Bomb : public Elapsing
{
private:
    int fireSize;
    int *pBombCounter;
    mapMatrix map;
public:
    Bomb(int _fireSize, int *_pBombCounter, MyTimer* timer, mapMatrix &_map);
    onStepArgument onStep();
    onBurnArgument onBurn();
};

#endif // BOMB_H
