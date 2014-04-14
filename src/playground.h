#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <vector>
#include "field.h"
#include "wall.h"
#include "ground.h"

class Playground
{
public:
    std::vector< std::vector< Field* > > map;
    //Field *map[13][11];
    Playground();
};

#endif // PLAYGROUND_H
