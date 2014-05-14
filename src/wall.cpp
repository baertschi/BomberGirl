#include "wall.h"
#include <iostream>

/****************************************************************************
 * Copyright (C) 2014 by bartm9                                             *
 *                                                                          *
 * This file is part of BomberGirl.                                         *
 *                                                                          *
 ****************************************************************************/

/**
 * @file wall.cpp
 * @author bartm9
 * @date 15 Mai 2014
 * @brief File containing wall class implementation
 *
 * A wall is a fixed block witch can't be destroyed. A given number of
 * Walls are placed at the beginning in a regular order on the map.
 *
 * @see https://github.com/baertschi/BomberGirl or
 * @see http://baertschi.github.io/BomberGirl/

 */


/** *************************************************************************
 * Constructor:     wall                                                    *
 ****************************************************************************
 *  @param[in] x, y  Field coordinate of the Wall
  ****************************************************************************/
Wall::Wall(int _x, int _y){
    x = _x;
    y = _y;
    image = wallImage;
    //std::cout << "wall " << x << "  " << y << "\n";
}

/** *************************************************************************
 * Method:     onBurn                                                       *
 ****************************************************************************
 * Implementation of the virtual method onBurn for the wall-field.
 * A wall can't burn
 *
 * @param[out]  HARDBLOCK    The fire can not destroy the brick
  ****************************************************************************/
onBurnArgument Wall::onBurn(){

    // return wall
    return HARDBLOCK;
}

/** *************************************************************************
 * Method:     onStep                                                       *
 ****************************************************************************
 * Implementation of the virtual method onStep for the wall-field.
 * One can not step on a wall-field
 *
 * @param[out]  NOENTRY   Player can't step on a wall
  ****************************************************************************/
onStepArgument Wall::onStep(){

    // return wall
    return NOENTRY;
}
