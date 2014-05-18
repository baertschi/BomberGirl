#include "player.h"

/****************************************************************************
 * Copyright (C) 2014 by bartm9                                             *
 *                                                                          *
 * This file is part of BomberGirl.                                         *
 *                                                                          *
 ****************************************************************************/

/**
 * @file player.cpp
 * @author bartm9
 * @date 15 Mai 2014
 * @brief File containing player class implementation
 *
 * The Player is independent from the rest of the map and is not a child of field
 *
 * @see https://github.com/baertschi/BomberGirl or
 * @see http://baertschi.github.io/BomberGirl/

 */


/** *************************************************************************
 * Constructor:     player                                                  *
 ****************************************************************************
 * Initialize the bombsize, firesize and number of bombs of the Player
  ****************************************************************************/
Player::Player()
{
    bombCounter = 0;
    maxBomb = 1;
    fireSize = 3;
}

/** *************************************************************************
 * Method:     walk                                                         *
 ****************************************************************************
 * Is executet after a KeyEvent and handles the logic for moving the player
 * on the playground
 *
 * @param   dir     Emumeration for the direction (UP, DOWN, LEFT, RIGHT)
 * @param   &map    Address of the map -> needed for onStep method call
  ****************************************************************************/
void Player::walk(directionEnum dir, const mapMatrix &map)
{
    // handle different walking directions
    int newX = x, newY = y;
    switch(dir)
    {
    case LEFT:
        newX--;
        break;
    case RIGHT:
        newX++;
        break;
    case UP:
        newY--;
        break;
    case DOWN:
        newY++;
        break;
    }

    // prove if new position is inside the playground
        if(newX >= 0 && newX <= 12 && newY >= 0 && newY <= 10)
        {
        // try to walk in this direction
        onStepArgument walkResult;
        walkResult = map[newX][newY]->onStep();

        switch(walkResult)
        {
        case NOENTRY:
            break;
        case ENTRY:
            x = newX;
            y = newY;
            break;
        case UPGRADEFLASH:
            fireSize++;
            x = newX;
            y = newY;
            static_cast<Ground *>(map[newX][newY])->itemElement = NULL;
            std::cout << "upgrade flash\n" << std::endl;
            break;
        case UPGRADEBOMBS:
            maxBomb++;
            x = newX;
            y = newY;
            static_cast<Ground *>(map[newX][newY])->itemElement = NULL;
            break;
        case DIE:
            // TODO: Die function
            x = newX;
            y = newY;
            break;
        }
    }
    else
    {
        return;
    }
}

/** *************************************************************************
 * Method:     placeBomb                                                    *
 ****************************************************************************
 * If a player drops a bomb a new Bomb needs to be created
 *
 * @param   &map    Address of the map -> needed to place the Bomb
  ****************************************************************************/
void Player::placeBomb(mapMatrix &map)
{
    // if the player still has bomb to place
    if(bombCounter < maxBomb && static_cast<Ground *>(map[x][y])->bombElement == NULL)
    {
        std::cout << "place bomb\n" << std::endl;
        bombCounter++;
        static_cast<Ground *>(map[x][y])->bombElement = new Bomb(x, y, fireSize, &bombCounter, tmr, &map);

    }
}
