#include "flashitem.h"

/****************************************************************************
 * Copyright (C) 2014 by bartm9                                             *
 *                                                                          *
 * This file is part of BomberGirl.                                         *
 *                                                                          *
 ****************************************************************************/

/**
 * @file bombitem.cpp
 * @author bartm9
 * @date 15 Mai 2014
 * @brief File Containing flashitem class implementation.
 *
 * flashitem appears after a brick is destroyed and disappears when a
 * player steps on the item. A flashitem increases the flashsize of the player
 * which steps over the flashitem.
 *
 * @see https://github.com/baertschi/BomberGirl or
 * @see http://baertschi.github.io/BomberGirl/

 */


/** *************************************************************************
 * Constructor:     flashitem                                                *
 ****************************************************************************
 * Creats flashitem-Object
 *
 * @param[in] x, y  Field coordinate of the Bombitem
  ****************************************************************************/
FlashItem::FlashItem(int _x, int _y){
    x = _x;
    y = _y;
    image = flashItemImage;
}

/** *************************************************************************
 * Method:     onStep                                                       *
 ****************************************************************************
 * Implementation of the virtual method onStep for the flashitem-field.
 * Upgrades the size of the fire
 *
 * @param[out]  UPGRADEFLASH Increases the size of the fire
  ****************************************************************************/
onStepArgument FlashItem::onStep(){
    return UPGRADEFLASH;
}

/** *************************************************************************
 * Method:     onBurn                                                       *
 ****************************************************************************
 * Implementation of the virtual method onBurn for the flashitem-field.
 * If a flashitem gets burned, nothing happens.
 *
 * @param[out]  NOACTION    The fire has no effect on the flashitem
  ****************************************************************************/
onBurnArgument FlashItem::onBurn(){
    return NOACTION;
}

