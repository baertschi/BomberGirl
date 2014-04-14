#include "playground.h"

Playground::Playground()
{
    // With normal C-style array, the map isn't automatically
    // initialized to NULL pointers. --> therefore using the
    // STL vector class for this (initialization given as last argument).
    map = mapMatrix ( 13, std::vector<Field*> ( 11, (Field*)NULL ) );

    // Initialize Map (Position [0, 0] is set to top left corner)
    for(int i = 1; i < 13; i+=2){
        for(int j = 1; j < 11; j +=2){
           map[i][j] = new Wall(i, j);     // not sure whether *map =... or map = ... is correct
        }
    }

    // Set Ground Field in each Corner
    map[0][0] = new Ground(0, 0);
    map[12][10] = new Ground(12, 10);
    for(int i = 1; i < 4; i++){
        int j = 0;
          map[i][j] = new Ground(i, j);
          map[j][i] = new Ground(j, i);
          map[12-i][10-j] = new Ground(12-i, 10-j);
          map[12-j][10-i] = new Ground(12-j, 10-i);
    }

    // Place Items, Bricks and remaining Ground Fields
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 11; j ++){
           if(map[i][j] == NULL){
               // TODO: place random Fields
               map[i][j] = new Ground(i, j);
           }
        }
    }

    // Initialize the two players
    player1.image = player1Image;
    player1.x = 0;
    player1.y = 0;

    player2.image = player2Image;
    player2.x = 12;
    player2.y = 10;
}
