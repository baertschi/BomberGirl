#include "extensionfire.h"

/****************************************************************************
 * Copyright (C) 2014 by bartm9                                             *
 *                                                                          *
 * This file is part of BomberGirl.                                         *
 *                                                                          *
 ****************************************************************************/

/**
 * @file extensionfire.cpp
 * @author bartm9
 * @date 15 Mai 2014
 * @brief File Containing extensionfire class implementation.
 *
 * Extensionfire is the fire-element which appears between corefire and endFire
 * If a player walks on the fire, he dies.
 *
 * @see https://github.com/baertschi/BomberGirl or
 * @see http://baertschi.github.io/BomberGirl/

 */


/** *************************************************************************
 * Constructor:     extensionfire                                           *
 ****************************************************************************
 * Creats extensionfire-Object
 *
 * @param[in] x, y  Field coordinate of the extensionfire
  ****************************************************************************/
ExtensionFire::ExtensionFire(int _x, int _y)
{
    x = _x;
    y = _y;
    image = extensionFireImage_u;
}

/** *************************************************************************
 * Method:     onBurn                                                       *
 ****************************************************************************
 * Implementation of the virtual method onBurn for the ExtensionFire-field.
 * A fire can't get burned
 *
 * @param[out]  NOACTION    Nothing happens
  ****************************************************************************/
onBurnArgument ExtensionFire::onBurn(){
    return NOACTION;
}

/** *************************************************************************
 * Method:     onStep                                                       *
 ****************************************************************************
 * Implementation of the virtual method onStep for the ExtensionFire-field.
 * If a player walks on the fire, he dies.
 *
 * @param[out]  DIE     Player dies -> Game over
  ****************************************************************************/
onStepArgument ExtensionFire::onStep(){
    return DIE;
}
