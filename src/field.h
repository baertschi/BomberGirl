#ifndef FIELD_H
#define FIELD_H
#include <QImage>

enum onStepReturnArgument {
    NOENTRY,
    ENTRY,
    UPGRADEFLASH,
    UPGRADEBOMBS,
    DIE
};

class Field
{
    int x, y;
    QImage image;
public:
    Field();
    enum onStepReturnArgument onStep();
    int onBurn();
    void draw();
};

#endif // FIELD_H
