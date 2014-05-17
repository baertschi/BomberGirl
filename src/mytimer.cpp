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
            //static_cast<Ground *>((*map)[(*it)->x][(*it)->y])->bombElement = NULL;

            //
        }

        elapsingList.clear();
    }

    //elapsingList.pop_back();


}
