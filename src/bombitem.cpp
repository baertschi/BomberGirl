#include "bombitem.h"

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
 * @brief File Containing bombitem class implementation.
 *
 * Bombitem appears after a brick is destroyed and disappears when a
 * player steps on the item. A bombitem increases the bombsize of the player
 * which steps over the bombitem.
 *
 * @see https://github.com/baertschi/BomberGirl or
 * @see http://baertschi.github.io/BomberGirl/

 */


/** *************************************************************************
 * Constructor:     Bombitem                                                *
 ****************************************************************************
 * Creats Bombitem-Object
 *
 * @param[in] x, y  Field coordinate of the Bombitem
  ****************************************************************************/
BombItem::BombItem(int _x, int _y){
    x = _x;
    y = _y;
    image = bombItemImage;
}

/** *************************************************************************
 * Method:     onStep                                                       *
 ****************************************************************************
 * Implementation of the virtual method onStep for the bombitem-field.
 * Upgrades the number of bombs a player can carry
 *
 * @param[out]  UPGRADEBOMBS Increases the number of bombs a player can have
  ****************************************************************************/
onStepArgument BombItem::onStep(){

    // return instruction to increase fireSize
    return UPGRADEBOMBS;
}

/** *************************************************************************
 * Method:     onBurn                                                       *
 ****************************************************************************
 * Implementation of the virtual method onBurn for the bombitem-field.
 * If a bombitem gets burned, nothing happens.
 *
 * @param[out]  NOACTION    The fire has no effect on the bombitem
  ****************************************************************************/
onBurnArgument BombItem::onBurn(){
    return NOACTION;
}
