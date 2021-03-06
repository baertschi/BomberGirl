#include "mytimer.h"

/****************************************************************************
 * Copyright (C) 2014 by bartm9                                             *
 *                                                                          *
 * This file is part of BomberGirl.                                         *
 *                                                                          *
 ****************************************************************************/

/**
 * @file mytimer.cpp
 * @author bartm9
 * @date 15 Mai 2014
 * @brief File Containing mytimer class implementation
 *
 * This class handles all time-dependent functions. All elapsing objects
 * are stored in a list. Every 100ms the list is updated.
 *
 * @see https://github.com/baertschi/BomberGirl or
 * @see http://baertschi.github.io/BomberGirl/

 */


/** *************************************************************************
 * Constructor:     mytimer                                                 *
 ****************************************************************************
 * Initialize the tick to 100ms
  ****************************************************************************/

MyTimer::MyTimer(QObject *parent, mapMatrix *_map) :
    QTimer(parent)
{
    map = _map;
    connect(this, SIGNAL(timeout()), this, SLOT(masterTick()));
    start(100);

}


/** *************************************************************************
 * Method:     masterTick                                                   *
 ****************************************************************************
 * This method is executed all 100ms. It handles all elapsing objects.
 * TODO: Propper handling of elapsing objects
  ****************************************************************************/
void MyTimer::masterTick()
{
    //std::cout << "tick";// go through list and tick all elapsing objects there
    // TODO: Es wird immer die ganze Liste durchgearbeitet und alle Enthaltenen Objekte gelöscht. Die Logik für das korrekte Zeithandling ist noch zu implementieren!!
    // Dazu muss jedes elapsing objekt mit einem countdown versehen werden

        std::list<Elapsing *>::iterator it;
        std::list<Elapsing *>::iterator iStart = elapsingList.begin();
        std::list<Elapsing *>::iterator iEnd = elapsingList.end();
        if(elapsingList.empty() == false){
            for(it = iStart; it != iEnd; it++){
                if((*it)->countdown == 0){
                    if((*it)->image == bombImage){
                        (*it)->onBurn();
                        //std::cout << "\n elapsing coordinates: "<< (*it)->x <<" "<< (*it)->y <<std::endl;
                        static_cast<Ground *>((*map)[(*it)->x][(*it)->y])->fireElement = new CoreFire((*it)->x, (*it)->y, this);

                        int i = 0;
                        bool blocked = false;
                        // Place Fire in all directions, add all fireelements to elapsing list

                        for(i = 1; i < static_cast<Ground *>((*map)[(*it)->x][(*it)->y])->bombElement->fireSize; i++){
                            int newX = (*it)->x;
                            int newY = (*it)->y + i;

                            // try to expand fire in all direction
                            onBurnArgument burnResult;
                            if(newX >= 0 && newX <= 12 && newY >= 0 && newY <= 10)
                            {
                                burnResult = static_cast<Ground *>((*map)[newX][newY])->onBurn();

                                if(blocked == false){
                                    switch(burnResult)
                                    {
                                    case NOACTION:
                                        if(static_cast<Ground *>((*map)[(*it)->x][(*it)->y])->bombElement->fireSize == i + 1){
                                            static_cast<Ground *>((*map)[newX][newY])->fireElement = new EndFire(newX, newY, this, D);
                                        }
                                        else{
                                            static_cast<Ground *>((*map)[newX][newY])->fireElement = new ExtensionFire(newX, newY, this, D);
                                        }
                                        break;
                                    case HARDBLOCK:
                                    // Stop iteration of i, so the next field after the wall don't burn
                                        blocked = true;
                                        break;
                                    case BLOCK:
                                        // If a field returns Block, stop the fire from expanding.
                                        static_cast<Ground *>((*map)[newX][newY])->fireElement = new EndFire(newX, newY,this, D);
                                        delete static_cast<Ground *>((*map)[newX][newY])->brickElement;
                                        static_cast<Ground *>((*map)[newX][newY])->brickElement = NULL;
                                        blocked = true;

                                        break;
                                    case TRIGGER:

                                        break;

                                    }
                                }
                            }
                        }
                        // UP
                        blocked = false;
                        // Place Fire in all directions, add all fireelements to elapsing list
                        for(i = 1; i < static_cast<Ground *>((*map)[(*it)->x][(*it)->y])->bombElement->fireSize; i++){
                            int newX = (*it)->x;
                            int newY = (*it)->y - i;

                            // try to expand fire in all direction
                            onBurnArgument burnResult;
                            if(newX >= 0 && newX <= 12 && newY >= 0 && newY <= 10)
                            {
                                burnResult = static_cast<Ground *>((*map)[newX][newY])->onBurn();

                                if(blocked == false){
                                    switch(burnResult)
                                    {
                                    case NOACTION:
                                        if(static_cast<Ground *>((*map)[(*it)->x][(*it)->y])->bombElement->fireSize == i + 1){
                                            static_cast<Ground *>((*map)[newX][newY])->fireElement = new EndFire(newX, newY,this, U);
                                        }
                                        else{
                                            static_cast<Ground *>((*map)[newX][newY])->fireElement = new ExtensionFire(newX, newY, this, U);
                                        }
                                        break;
                                    case HARDBLOCK:
                                        blocked = true;
                                        break;
                                    case BLOCK:
                                        static_cast<Ground *>((*map)[newX][newY])->fireElement = new EndFire(newX, newY, this, U);
                                        delete static_cast<Ground *>((*map)[newX][newY])->brickElement;
                                        static_cast<Ground *>((*map)[newX][newY])->brickElement = NULL;
                                        blocked = true;

                                        break;
                                    case TRIGGER:

                                        break;

                                    }
                                }
                            }
                        }
                        // LEFT
                        blocked = false;
                        for(i = 1; i < static_cast<Ground *>((*map)[(*it)->x][(*it)->y])->bombElement->fireSize; i++){
                            int newX = (*it)->x - i;
                            int newY = (*it)->y;

                            // try to expand fire in all direction
                            onBurnArgument burnResult;
                            if(newX >= 0 && newX <= 12 && newY >= 0 && newY <= 10)
                            {
                                burnResult = static_cast<Ground *>((*map)[newX][newY])->onBurn();

                                if(blocked == false){
                                    switch(burnResult)
                                    {
                                    case NOACTION:
                                        if(static_cast<Ground *>((*map)[(*it)->x][(*it)->y])->bombElement->fireSize == i + 1){
                                            static_cast<Ground *>((*map)[newX][newY])->fireElement = new EndFire(newX, newY,this, L);
                                        }
                                        else{
                                            static_cast<Ground *>((*map)[newX][newY])->fireElement = new ExtensionFire(newX, newY, this, L);
                                        }
                                        break;
                                    case HARDBLOCK:
                                    blocked = true;
                                        break;
                                    case BLOCK:
                                        static_cast<Ground *>((*map)[newX][newY])->fireElement = new EndFire(newX, newY, this, L);
                                        delete static_cast<Ground *>((*map)[newX][newY])->brickElement;
                                        static_cast<Ground *>((*map)[newX][newY])->brickElement = NULL;
                                        blocked = true;

                                        break;
                                    case TRIGGER:

                                        break;

                                    }
                                }
                            }
                        }
                        // RIGHT
                        blocked = false;
                        for(i = 1; i < static_cast<Ground *>((*map)[(*it)->x][(*it)->y])->bombElement->fireSize; i++){
                            int newX = (*it)->x + i;
                            int newY = (*it)->y;

                            // try to expand fire in all direction
                            onBurnArgument burnResult;
                            if(newX >= 0 && newX <= 12 && newY >= 0 && newY <= 10)
                            {
                                burnResult = static_cast<Ground *>((*map)[newX][newY])->onBurn();

                                if(blocked == false){
                                    switch(burnResult)
                                    {
                                    case NOACTION:
                                        if(static_cast<Ground *>((*map)[(*it)->x][(*it)->y])->bombElement->fireSize == i + 1){
                                            static_cast<Ground *>((*map)[newX][newY])->fireElement = new EndFire(newX, newY,this, R);
                                        }
                                        else{
                                            static_cast<Ground *>((*map)[newX][newY])->fireElement = new ExtensionFire(newX, newY, this, R);
                                        }
                                        break;
                                    case HARDBLOCK:
                                        blocked = true;
                                        break;
                                    case BLOCK:
                                        static_cast<Ground *>((*map)[newX][newY])->fireElement = new EndFire(newX, newY,this, R);
                                        delete static_cast<Ground *>((*map)[newX][newY])->brickElement;
                                        static_cast<Ground *>((*map)[newX][newY])->brickElement = NULL;
                                        blocked = true;

                                        break;
                                    case TRIGGER:

                                        break;

                                    }
                                }
                            }
                        }
                        // Delete Bomb from elapsinglist
                        int temp_x, temp_y;
                        temp_x = (*it)->x;
                        temp_y = (*it)->y;
                        detach(*it);
                        // delete Bomb-object (not sure which line is correct)
                        delete static_cast<Ground *>((*map)[temp_x][temp_y])->bombElement;
                        static_cast<Ground *>((*map)[temp_x][temp_y])->bombElement = NULL;

                    }
                    else{
                        int temp_x, temp_y;
                        temp_x = (*it)->x;
                        temp_y = (*it)->y;
                        detach(*it);
                        // delete Fire-object (not sure which line is correct, but it works somehow *magic*)
                        delete static_cast<Ground *>((*map)[temp_x][temp_y])->fireElement;
                        static_cast<Ground *>((*map)[temp_x][temp_y])->fireElement = NULL;
                        //std::cout << " deleted: "<< std::endl;
                    }
                }
                else{
                    (*it)->countdown--;
                    //std::cout << " countdown: "<< (*it)->countdown<< std::endl;
                }


            }
        }

        //elapsingList.pop_back();
}

/** *************************************************************************
 * Method:     attach                                                   *
 ****************************************************************************
 * Adds an object to the elapsingList
 *
 * @param[in]   *observer   The object which should be attached
  ****************************************************************************/
void MyTimer::attach(Elapsing *observer)
{
    elapsingList.push_front(observer);
}

/** *************************************************************************
 * Method:     detach                                                   *
 ****************************************************************************
 * If an object should dissappear it needs to be deletet out of the list and
 * the onBurn mehtod needs to be executed.
 *
 * TODO: Propper handling of elapsing objects
  ****************************************************************************/
void MyTimer::detach(Elapsing *observer){

    elapsingList.remove(observer);

}
