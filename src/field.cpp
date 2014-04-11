#include "field.h"
#include<iostream>
Field::Field(){

}

Field::Field(int _x, int _y)
{
    x = _x;
    y = _y;
}
void Field::draw(){
    // draw image
    std::cout << "draw image";
}
