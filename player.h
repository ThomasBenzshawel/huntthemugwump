#ifndef PLAYER_H_
#define PLAYER_H_

#include "character.h"

class player{
private:
   int numBombs =4;
public:
    player(/* args */);
    ~player();
    player(map*, int x, int y);
};


#endif