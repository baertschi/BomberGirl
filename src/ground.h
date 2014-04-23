#ifndef GROUND_H
#define GROUND_H
#include "field.h"
#include "fieldcontent.h"
#include "bombitem.h"
#include "bomb.h"
#include "flashitem.h"
#include "brick.h"
#include "playground.h"

class Ground : public Field
{
private:
    FieldContent *fieldContents[4];
public:
    Ground();
    Ground(int _x, int _y);
    Ground(int _x, int _y, BombItem *theBombItem);
    Ground(int _x, int _y, FlashItem *theFlashItem);
    Ground(int _x, int _y, Brick *theBrick);
    onStepArgument onStep();
    onBurnArgument onBurn();
    void placeBomb();

};

#endif // GROUND_H
