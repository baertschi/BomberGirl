#ifndef FIELD_H
#define FIELD_H
#include <QPixmap>

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
public:
    Field();
    Field(int _x, int _y);
    virtual enum onStepArgument onStep() = 0;
    virtual enum onBurnArgument onBurn() = 0;
    QPixmap* image;
};

#endif // FIELD_H
