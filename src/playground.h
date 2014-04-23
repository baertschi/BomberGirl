#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <vector>
#include "field.h"
#include "wall.h"
#include "ground.h"
#include "player.h"
#include "bombitem.h"
#include "bomb.h"
#include "flashitem.h"
#include "brick.h"

typedef std::vector< std::vector< Field* > > mapMatrix;

class Playground
{
public:
    Playground();

    mapMatrix map;
    Player player1, player2;
};

#endif // PLAYGROUND_H
