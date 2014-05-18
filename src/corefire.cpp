#include "corefire.h"

/****************************************************************************
 * Copyright (C) 2014 by bartm9                                             *
 *                                                                          *
 * This file is part of BomberGirl.                                         *
 *                                                                          *
 ****************************************************************************/

/**
 * @file corefire.cpp
 * @author bartm9
 * @date 15 Mai 2014
 * @brief File Containing corefire class implementation.
 *
 * Corefire is the fire-element which appears in the middle of the fire
 * (in the same field as the bomb was). If a player walks on the fire,
 * he dies.
 *
 * @see https://github.com/baertschi/BomberGirl or
 * @see http://baertschi.github.io/BomberGirl/

 */


/** *************************************************************************
 * Constructor:     corefire                                                *
 ****************************************************************************
 * Creats corefire-Object
 *
 * @param[in] x, y  Field coordinate of the Bombitem
  ****************************************************************************/
CoreFire::CoreFire(int _x, int _y, MyTimer* timer)
{
    x = _x;
    y = _y;
    image = coreFireImage;
    countdown = 20;
    timer->attach(this);
    //std::cout << "corefire created"<< std::endl;
}

/** *************************************************************************
 * Method:     onBurn                                                       *
 ****************************************************************************
 * Implementation of the virtual method onBurn for the corefire-field.
 * A fire can't get burned
 *
 * @param[out]  NOACTION    Nothing happens
  ****************************************************************************/
onBurnArgument CoreFire::onBurn(){
    return NOACTION;
}

/** *************************************************************************
 * Method:     onStep                                                       *
 ****************************************************************************
 * Implementation of the virtual method onStep for the corefire-field.
 * If a player walks on the fire, he dies.
 *
 * @param[out]  DIE     Player dies -> Game over
  ****************************************************************************/
onStepArgument CoreFire::onStep(){
    return DIE;
}
