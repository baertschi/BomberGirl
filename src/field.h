#ifndef FIELD_H
#define FIELD_H
#include <QImage>

enum onStepArgument {
    NOENTRY,
    ENTRY,
    UPGRADEFLASH,
    UPGRADEBOMBS,
    DIE
};
enum onBurnArgument {
    NOACTION,
    HARDBLOCK,
    BLOCK,
    BURN,
    TRIGGER
};

class Field
{
protected:
    int x, y;
    QImage image;
public:
    Field();
    Field(int _x, int _y);
    virtual enum onStepArgument onStep() = 0;
    virtual enum onBurnArgument onBurn() = 0;
    void draw();
};

#endif // FIELD_H
