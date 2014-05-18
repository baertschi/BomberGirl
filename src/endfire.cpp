#include "endfire.h"

/****************************************************************************
 * Copyright (C) 2014 by bartm9                                             *
 *                                                                          *
 * This file is part of BomberGirl.                                         *
 *                                                                          *
 ****************************************************************************/

/**
 * @file endfire.cpp
 * @author bartm9
 * @date 15 Mai 2014
 * @brief File Containing endfire class implementation.
 *
 * Endfire is the fire-element which appears at the endof the fire.
 * If a player walks on the fire, he dies.
 *
 * @see https://github.com/baertschi/BomberGirl or
 * @see http://baertschi.github.io/BomberGirl/

 */


/** *************************************************************************
 * Constructor:     EndFire                                                 *
 ****************************************************************************
 * Creats extensionfire-Object
 *
 * @param[in] x, y  Field coordinate of the EndFire
  ****************************************************************************/
EndFire::EndFire(int _x, int _y, orientation ori)
{
    x = _x;
    y = _y;
    switch(ori){
    case L:
        image = endFireImage_l;
        break;
    case R:
        image = endFireImage_r;
        break;
    case U:
        image = endFireImage_u;
        break;
    case D:
        image = endFireImage_d;
        break;
    }

}

/** *************************************************************************
 * Method:     onBurn                                                       *
 ****************************************************************************
 * Implementation of the virtual method onBurn for the EndFire-field.
 * A fire can't get burned
 *
 * @param[out]  NOACTION    Nothing happens
  ****************************************************************************/
onBurnArgument EndFire::onBurn(){
    return NOACTION;
}

/** *************************************************************************
 * Method:     onStep                                                       *
 ****************************************************************************
 * Implementation of the virtual method onStep for the EndFire-field.
 * If a player walks on the fire, he dies.
 *
 * @param[out]  DIE     Player dies -> Game over
  ****************************************************************************/
onStepArgument EndFire::onStep(){
    return DIE;
}
