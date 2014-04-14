#include "flashitem.h"

FlashItem::FlashItem()
{
}
FlashItem::FlashItem(int _x, int _y){
    x = _x;
    y = _y;
    image = flashItemImage;
}
onStepArgument FlashItem::onStep(){
    return UPGRADEFLASH;
}
onBurnArgument FlashItem::onBurn(){
    return NOACTION;
}
