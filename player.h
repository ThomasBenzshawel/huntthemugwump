#ifndef PLAYER_H_
#define PLAYER_H_

#include "character.h"

class player : public character{
private:
   int numBomb;
   bool hasTrapSheild=false;
   bool hasWumpSheild=false;
public:
    ~player();
    player(map*, int x, int y);
};


#endif