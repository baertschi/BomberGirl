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
{
    std::list<Elapsing *>::iterator it;
    std::list<Elapsing *>::iterator iStart = elapsingList.begin();
    std::list<Elapsing *>::iterator iEnd = elapsingList.end();
    if(elapsingList.empty() == false){
        for(it = iStart; it != iEnd; it++){

            (*it)->onBurn();
            std::cout << "\n elapsing coordinates: "<< (*it)->x <<" "<< (*it)->y <<std::endl;
            static_cast<Ground *>((*map)[(*it)->x][(*it)->y])->fireElement = new CoreFire((*it)->x, (*it)->y);

            int newX = (*it)->x;
            int newY = (*it)->y - 1;

            // try to expand fire in all direction
            onBurnArgument burnResult;
            if(newX >= 0 && newX <= 12 && newY >= 0 && newY <= 10)
            {
                burnResult = static_cast<Ground *>((*map)[newX][newY])->onBurn();

                switch(burnResult)
                {
                case NOACTION:
                    static_cast<Ground *>((*map)[newX][newY])->fireElement = new ExtensionFire(newX, newY);
                    break;
                case HARDBLOCK:

                    break;
                case BLOCK:
                    static_cast<Ground *>((*map)[newX][newY])->fireElement = new ExtensionFire(newX, newY);
                    static_cast<Ground *>((*map)[newX][newY])->brickElement = NULL;
                    break;
                case TRIGGER:

                    break;

                }
            }

            static_cast<Ground *>((*map)[(*it)->x][(*it)->y])->bombElement = NULL;

        }

        elapsingList.clear();
    }

    //elapsingList.pop_back();


}
