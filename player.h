#ifndef PLAYER_H_
#define PLAYER_H_

#include "character.h"

class player : public character{
private:
    /* data */
public:
    player(/* args */);
    ~player();
    player(map*, int x, int y);
};


#endif