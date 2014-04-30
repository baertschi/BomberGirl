#include "player.h"

Player::Player()
{
    bombCounter = 0;
    maxBomb = 1;
    fireSize = 3;
}

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
            break;
        case UPGRADEBOMBS:
            maxBomb++;
            x = newX;
            y = newY;
            break;
        case DIE:
            // TODO: Die function
            break;
        }
    }
    else
    {
        return;
    }
}

void Player::placeBomb(mapMatrix &map)
{
    // if the player still has bomb to place
    if(bombCounter < maxBomb)
    {
        bombCounter++;
        map[x][y] = new Bomb(fireSize, &bombCounter);

    }
}
