#include "field.h"
#include<iostream>

/****************************************************************************
 * Copyright (C) 2014 by bartm9                                             *
 *                                                                          *
 * This file is part of BomberGirl.                                         *
 *                                                                          *
 ****************************************************************************/

/**
 * @file field.cpp
 * @author bartm9
 * @date 15 Mai 2014
 * @brief File Containing virtual class field.
 *
 * Superclass for all fields of the playground. For the Visitor-Pattern
 * it has two virtual functions onStep and onBurn, which will be difined
 * for every child-class
 *
 * @see https://github.com/baertschi/BomberGirl or
 * @see http://baertschi.github.io/BomberGirl/

 */


/** *************************************************************************
 * Constructor:     filed                                                   *
 ****************************************************************************
 * Virtual Class, therfore no implementation needed
  ****************************************************************************/
Field::Field(){

}

Field::Field(int _x, int _y)
{
    x = _x;
    y = _y;
}
