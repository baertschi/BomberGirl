#include "brick.h"

/****************************************************************************
 * Copyright (C) 2014 by bartm9                                             *
 *                                                                          *
 * This file is part of BomberGirl.                                         *
 *                                                                          *
 ****************************************************************************/

/**
 * @file brick.cpp
 * @author bartm9
 * @date 15 Mai 2014
 * @brief File Containing brick class implementation.
 *
 * A brick is a field which is like a wall in the first place, but it can
 * be destroyed by the fire.
 *
 * @see https://github.com/baertschi/BomberGirl or
 * @see http://baertschi.github.io/BomberGirl/

 */


/** *************************************************************************
 * Constructor:     Brick                                                   *
 ****************************************************************************
 * Creats Brick-Object
 *
 * @param[in] x, y  Field coordinate of the Bombitem
  ****************************************************************************/
Brick::Brick(int _x, int _y){
    x = _x;
    y = _y;
    image = brickImage;
}

/** *************************************************************************
 * Method:     onBurn                                                       *
 ****************************************************************************
 * Implementation of the virtual method onBurn for the brick-field.
 * If a brick gets burned, it dissapears and the content which is underneath
 * appears
 *
 * @param[out]  BLOCK    The fire destroys the brick
  ****************************************************************************/
onBurnArgument Brick::onBurn(){
    return BLOCK;
}


/** *************************************************************************
 * Method:     onStep                                                       *
 ****************************************************************************
 * Implementation of the virtual method onStep for the brick-field.
 * One can not step on a brick-field
 *
 * @param[out]  NOENTRY   Player can't step on a brick
  ****************************************************************************/
onStepArgument Brick::onStep(){
    return NOENTRY;
}

