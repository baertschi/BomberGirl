#include "playground.h"
#include "wall.h"
#include "ground.h"


Playground::Playground()
{
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
    for(int i = 1; i < 13; i++){
        for(int j = 1; j < 11; j ++){
           if(map[i][j] == NULL){
               // TODO: place random Fields
               map[i][j] = new Ground(i, j);
           }
        }
    }
}
