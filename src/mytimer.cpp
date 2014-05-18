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
    std::cout << "tick";// go through list and tick all elapsing objects there
    detach();
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
void MyTimer::detach(/*Elapsing *observer*/)
// TODO: Es wird immer die ganze Liste durchgearbeitet und alle Enthaltenen Objekte gelöscht. Die Logik für das korrekte Zeithandling ist noch zu implementieren!!
// Dazu muss jedes elapsing objekt mit einem countdown versehen werden
{
    std::list<Elapsing *>::iterator it;
    std::list<Elapsing *>::iterator iStart = elapsingList.begin();
    std::list<Elapsing *>::iterator iEnd = elapsingList.end();
    if(elapsingList.empty() == false){
        for(it = iStart; it != iEnd; it++){
            if((*it)->countdown == 0){
                (*it)->onBurn();
                std::cout << "\n elapsing coordinates: "<< (*it)->x <<" "<< (*it)->y <<std::endl;
                static_cast<Ground *>((*map)[(*it)->x][(*it)->y])->fireElement = new CoreFire((*it)->x, (*it)->y);

                int i = 0;
                bool blocked = false;
                // TODO: Place Fire in all directions, add all fireelements to elapsing list
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
                                    static_cast<Ground *>((*map)[newX][newY])->fireElement = new EndFire(newX, newY, D);
                                }
                                else{
                                    static_cast<Ground *>((*map)[newX][newY])->fireElement = new ExtensionFire(newX, newY, D);
                                }
                                break;
                            case HARDBLOCK:
                            // TODO: Stop iteration of i, so the next field after the wall don't burn
                                blocked = true;
                                break;
                            case BLOCK:
                                // TODO: If a field returns Block, stop the fire from expanding.
                                static_cast<Ground *>((*map)[newX][newY])->fireElement = new EndFire(newX, newY, D);
                                delete static_cast<Ground *>((*map)[newX][newY])->brickElement;
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
                // TODO: Place Fire in all directions, add all fireelements to elapsing list
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
                                    static_cast<Ground *>((*map)[newX][newY])->fireElement = new EndFire(newX, newY, U);
                                }
                                else{
                                    static_cast<Ground *>((*map)[newX][newY])->fireElement = new ExtensionFire(newX, newY, U);
                                }
                                break;
                            case HARDBLOCK:
                                blocked = true;
                                break;
                            case BLOCK:
                                static_cast<Ground *>((*map)[newX][newY])->fireElement = new EndFire(newX, newY, U);
                                delete static_cast<Ground *>((*map)[newX][newY])->brickElement;
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
                                    static_cast<Ground *>((*map)[newX][newY])->fireElement = new EndFire(newX, newY, L);
                                }
                                else{
                                    static_cast<Ground *>((*map)[newX][newY])->fireElement = new ExtensionFire(newX, newY, L);
                                }
                                break;
                            case HARDBLOCK:
                            blocked = true;
                                break;
                            case BLOCK:
                                static_cast<Ground *>((*map)[newX][newY])->fireElement = new EndFire(newX, newY, L);
                                delete static_cast<Ground *>((*map)[newX][newY])->brickElement;
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
                    int newX = (*it)->x + 1;
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
                                    static_cast<Ground *>((*map)[newX][newY])->fireElement = new EndFire(newX, newY, R);
                                }
                                else{
                                    static_cast<Ground *>((*map)[newX][newY])->fireElement = new ExtensionFire(newX, newY, R);
                                }
                                break;
                            case HARDBLOCK:
                                blocked = true;
                                break;
                            case BLOCK:
                                static_cast<Ground *>((*map)[newX][newY])->fireElement = new EndFire(newX, newY, R);
                                delete static_cast<Ground *>((*map)[newX][newY])->brickElement;
                                blocked = true;

                                break;
                            case TRIGGER:

                                break;

                            }
                        }
                    }
                }

                delete static_cast<Ground *>((*map)[(*it)->x][(*it)->y])->bombElement;
                elapsingList.clear();
            }
            else{
                (*it)->countdown--;
                std::cout << " onburn end "<< (*it)->countdown<< std::endl;
            }


        }
    }

    //elapsingList.pop_back();


}
