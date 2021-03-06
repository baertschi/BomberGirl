#ifndef PLAYER_H
#define PLAYER_H
#include "field.h"
#include "ground.h"
#include "mytimer.h"



enum directionEnum {LEFT, RIGHT, UP, DOWN};

typedef std::vector< std::vector< Field* > > mapMatrix;

class Player
{
private:
    int bombCounter, maxBomb, fireSize;

public:
    Player();

    void die();
    void walk(directionEnum dir, const mapMatrix &map);
    void placeBomb(mapMatrix &map);

    int x, y;
    imageEnum image;
    MyTimer *tmr;
};

#endif // PLAYER_H
