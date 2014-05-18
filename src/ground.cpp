#include "ground.h"
#include <iostream>

/****************************************************************************
 * Copyright (C) 2014 by bartm9                                             *
 *                                                                          *
 * This file is part of BomberGirl.                                         *
 *                                                                          *
 ****************************************************************************/

/**
 * @file ground.cpp
 * @author bartm9
 * @date 15 Mai 2014
 * @brief File Containing ground class implementation.
 *
 * Every field which is no wall is a ground-field. A ground-field can
 * contain multiple superior layers of fields. e.g. an item an a brick.
 *
 * @see https://github.com/baertschi/BomberGirl or
 * @see http://baertschi.github.io/BomberGirl/

 */



/** *************************************************************************
 * Constructor:     ground                                                  *
 ****************************************************************************
 * Creats ground-Object with a set of initial values. The constructor is
 * overloaded.
 *
 * @param[in] _x, _y    Field coordinate of the Ground-field
 *
 * @param[in]  *_theBombItem    Generates a Groundfield with a Bombitem on top
 *
 * @param[in]  *_theFlashItem   Generates a Groundfield with a Flashitem on top
 *
 * @param[in]   *_theBrick  Generates a Groundfield with a Brick on top
  ****************************************************************************/
Ground::Ground()
{
    itemElement = NULL;
    fireElement = NULL;
    bombElement = NULL;
    brickElement = NULL;

}
Ground::Ground(int _x, int _y){
    Ground();
    x = _x;
    y = _y;
    image = groundImage;
}
Ground::Ground(int _x, int _y, BombItem *_theBombItem){
    Ground(_x, _y);
    itemElement = _theBombItem;
    brickElement = new Brick(_x, _y);

}

Ground::Ground(int _x, int _y, FlashItem *_theFlashItem){
    Ground(_x, _y);
    itemElement = _theFlashItem;
    brickElement = new Brick(_x, _y);

}

Ground::Ground(int _x, int _y, Brick *_theBrick){
    Ground(_x, _y);
    brickElement = _theBrick;

}

/** *************************************************************************
 * Method:     onStep                                                       *
 ****************************************************************************
 * Implementation of the virtual method onStep for the ground-field.
 * Because a ground field can contain multiple fields, it is necessary to
 * distinguish for all cases.
 *
 * @param[out]  onStepArgument Enum wich defines all options for the onStep-
 * method
  ****************************************************************************/
onStepArgument Ground::onStep(){
    // first execute onStep Method of fieldContents (highest priority first)
    if(brickElement != NULL || bombElement != NULL){
        return NOENTRY;
    }
    else if(fireElement != NULL){
        return DIE;
    }
    else if(itemElement != NULL){
        if(itemElement->image == flashItemImage){
            return UPGRADEFLASH;
        }
        else{
            return UPGRADEBOMBS;
        }
    }
    return ENTRY;
}

/** *************************************************************************
 * Method:     onBurn                                                       *
 ****************************************************************************
 * Implementation of the virtual method onBurn for the ground-field.
 * If a ground-field gets burned, nothing happens
 *
 * @param[out]  NOACTION Enum which defines all options for the onBurn-method
  ****************************************************************************/
onBurnArgument Ground::onBurn(){
    // block, trigger, noaction
    if(brickElement != NULL){
        return BLOCK;
    }
    if(bombElement != NULL){
        return TRIGGER;
    }
    return NOACTION;
}


void placeBomb(){

}
