#ifndef PLAYGROUND_H
#define PLAYGROUND_H
#include "field.h"
#include <vector>

class Playground
{
public:
    //std::vector< std::vector< *Field > > map;
    Field *map[13][11];
    Playground();
};

#endif // PLAYGROUND_H
