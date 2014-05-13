#include "bomb.h"
#include "mainwindow.h"

/****************************************************************************
 * Copyright (C) 2014 by bartm9                                             *
 *                                                                          *
 * This file is part of BomBer.                                             *
 *                                                                          *
 *   This Game is free software: you can redistribute it and/or modify it   *
 *   under the terms of the GNU Lesser General Public License as published  *
 *   by the Free Software Foundation, either version 3 of the License, or   *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   It is distributed in the hope that it will be useful,                  *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU Lesser General Public License for more details.                    *
 *                                                                          *
 ****************************************************************************/

/**
 * @file bomb.cpp
 * @author bartm9
 * @date 15 Mai 2014
 * @brief File Containing bomb class implementation.
 *
 * Here typically goes a more extensive explanation of what the header
 * defines. Doxygens tags are words preceeded by either a backslash @\
 * or by an at symbol @@.
 * @see https://github.com/baertschi/BomberGirl

 */
Bomb::Bomb(int _fireSize, int *_pBombCounter, MyTimer* timer, const mapMatrix &_map)
{
    fireSize = _fireSize;
    pBombCounter = _pBombCounter;
    image = bombImage;
    map = _map;
    timer->attach(this);

}

onStepArgument Bomb::onStep(){
    return NOENTRY;
}

onBurnArgument Bomb::onBurn(){
    // TODO: trigger bomb immediately!
    std::cout << " onburn vor corefire"<< std::endl;
    *pBombCounter = *pBombCounter - 1;
    std::cout << " onburn vor corefire"<< std::endl;
    static_cast<Ground *>(map[x][y])->fireElement = new CoreFire(x, y);
    std::cout << "\n onburn\n"<< std::endl;
    //static_cast<Ground *>(map[x][y])->bombElement = NULL;

    std::cout << " onburn vor corefire"<< std::endl;

    return TRIGGER;
}
