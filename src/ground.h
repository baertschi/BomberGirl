#ifndef GROUND_H
#define GROUND_H
#include "field.h"
#include "fieldcontent.h"
#include "bombitem.h"
#include "bomb.h"
#include "flashitem.h"
#include "brick.h"
#include "fire.h"
#include "playground.h"

class Ground : public Field
{
private:

public:
    Ground();
    Ground(int _x, int _y);
    Ground(int _x, int _y, BombItem *theBombItem);
    Ground(int _x, int _y, FlashItem *theFlashItem);
    Ground(int _x, int _y, Brick *theBrick);
    onStepArgument onStep();
    onBurnArgument onBurn();
    void placeBomb();

    Item *itemElement;
    Fire *fireElement;
    Bomb *bombElement;
    Brick *brickElement;
};

#endif // GROUND_H
