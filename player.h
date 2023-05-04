#ifndef PLAYER_H_
#define PLAYER_H_

#include "character.h"

class player{
public:
    int current_x;
    int current_y;
    char who;
   int numBomb=0;
   map *occupiedMap;
   bool isAlive = true;
   bool hasTrapSheild=false;
   bool hasWumpSheild=false;
   player(map* mainMap, int x, int y, char who);
    ~player();
    int move(char direction,char who);
    bool initializeCharacter(cell *currentCell);
};


#endif