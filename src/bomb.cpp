#include "bomb.h"
#include "mainwindow.h"

/****************************************************************************
 * Copyright (C) 2014 by bartm9                                             *
 *                                                                          *
 * This file is part of BomberGirl.                                         *
 *                                                                          *
 ****************************************************************************/

/**
 * @file bomb.cpp
 * @author bartm9
 * @date 15 Mai 2014
 * @brief File Containing bomb class implementation.
 *
 * Bomb explode after a certain time and handles the fire. One can not
 * step on a bomb.
 *
 * @see https://github.com/baertschi/BomberGirl or
 * @see http://baertschi.github.io/BomberGirl/

 */




/** *************************************************************************
 * Constructor:     Bomb                                                    *
 ****************************************************************************
 * Creats Bomb-Object with a set of initial values
 *
 * @param[in] _fireSize The Diameter of the Fire, wich appear when the bomb
 * exploads. This value is always odd.
 * @param[in]  *_bompCounter    Pointer to the Variable of the Player, wich
 * counts the number of bombs a player can set.
 * @param[in]  *timer   Pointer to the Timer, so the Bomb knows where to
 * attach itself to the elapsingList
 * @param[in]   &_map   Address of of the map, to place the fireElements
  ****************************************************************************/
Bomb::Bomb(int _fireSize, int *_pBombCounter, MyTimer* timer, mapMatrix *_map)
{
    fireSize = _fireSize;
    pBombCounter = _pBombCounter;
    image = bombImage;
    map = _map;
    timer->attach(this);

}

/** *************************************************************************
 * Method:     onStep                                                       *
 ****************************************************************************
 * Implementation of the virtual method onStep for the bomb-field.
 * One can not step on a bomb, therefore it returns NOENTRY
 *
 * @param[out]  NOENTRY Enum wich defines all options for the onStep-method
 * Noentry means the player can't walk in this field
  ****************************************************************************/
onStepArgument Bomb::onStep(){
    return NOENTRY;
}

/** *************************************************************************
 * Method:     onBurn                                                       *
 ****************************************************************************
 * Implementation of the virtual method onBurn for the bomb-field.
 * If a bomb gets burned, the bomb triggers. The bomb-counter of the player
 * needs to be decremented.
 *
 * @param[out]  TRIGGER Enum which defines all options for the onBurn-method
 * TRIGGER means the bomb was triggerd
  ****************************************************************************/
onBurnArgument Bomb::onBurn(){
    // TODO: trigger bomb immediately!

    *pBombCounter = *pBombCounter - 1;
    std::cout << " onburn vor corefire"<< std::endl;
    //static_cast<Ground *>((*map)[x][y])->fireElement = new CoreFire(x, y);
    std::cout << "\n onburn: \n"<< std::endl;
    //static_cast<Ground *>((*map)[x][y])->bombElement = NULL;

    std::cout << " onburn end "<< std::endl;

    return TRIGGER;
}
