#ifndef PLAYER_H
#define PLAYER_H
#include <QImage>

class Player
{
private:
    int bombCounter, maxBomb, fireSize;
    int x, y;
    QImage image;

public:
    Player();

    void die();
    void walk();
    void placeBomb();
    void draw();
};

#endif // PLAYER_H