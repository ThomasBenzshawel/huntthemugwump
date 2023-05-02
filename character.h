#ifndef _character_h
#define _character_h

class map;
class cell;

class character
{
public:
  int current_x;
  int current_y;
  char who;
     map *occupiedMap;
    character(map *map, int startx, int starty,char who);
    ~character();
    bool move();
    bool initializeCharacter(cell *currentCell);


};

#endif