#ifndef FIELD_H
#define FIELD_H
#include <QPixmap>


enum imageEnum {
groundImage, bombImage, wallImage, brickImage,
bombItemImage, flashItemImage, coreFireImage,
extensionFireImage_l,extensionFireImage_r,extensionFireImage_u,extensionFireImage_d,endFireImage_l,endFireImage_r,endFireImage_u,endFireImage_d, player1Image, player2Image
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


public:
    Field();
    Field(int _x, int _y);
    virtual enum onStepArgument onStep() = 0;
    virtual enum onBurnArgument onBurn() = 0;

    int x, y;
    imageEnum image;
};

#endif // FIELD_H
