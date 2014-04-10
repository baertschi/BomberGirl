#ifndef BOMB_H
#define BOMB_H
#include "elapsing.h"

class Bomb : public Elapsing
{
private:
    int fireSize;
    int *pBombCounter;
public:
    Bomb(int _fireSize, int *_pBombCounter);
};

#endif // BOMB_H
