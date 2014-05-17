#ifndef FIELD_H
#define FIELD_H
#include <QPixmap>


enum imageEnum {
groundImage, bombImage, wallImage, brickImage,
bombItemImage, flashItemImage, coreFireImage,
extensionFireImage,endFireImage, player1Image, player2Image
};

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

    imageEnum image;
};

#endif // FIELD_H
