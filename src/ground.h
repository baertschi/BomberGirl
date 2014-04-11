#ifndef GROUND_H
#define GROUND_H
#include "field.h"
#include "fieldcontent.h"

class Ground : public Field
{
private:
   // FieldContent fieldContents[4];
public:
    Ground();
    Ground(int _x, int _y);
    onStepArgument onStep();
    onBurnArgument onBurn();
    void placeBomb();
};

#endif // GROUND_H
