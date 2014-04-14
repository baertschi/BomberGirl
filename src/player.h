#ifndef PLAYER_H
#define PLAYER_H
#include "mainwindow.h"

class Player
{
private:
    int bombCounter, maxBomb, fireSize;
    int x, y;

public:
    Player();

    void die();
    void walk();
    void placeBomb();
    void draw();

    imageEnum image;
};

#endif // PLAYER_H
