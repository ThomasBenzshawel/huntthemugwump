#ifndef PLAYER_H_
#define PLAYER_H_

#include "character.h"

class player : public character{
public:
   int numBomb=0;
   bool isAlive = true;
   bool hasTrapSheild=false;
   bool hasWumpSheild=false;
    ~player();
    player(map*, int x, int y,char who);
    bool move(char direction,char who);
};


#endif