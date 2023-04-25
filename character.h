#ifndef _character_h
#define _character_h

class map;
class cell;

class character
{
private:
  int current_x;
  int current_y;
  map *occupiedMap;
public:
    character(map *map, int startx, int starty);
    ~character();
    bool move(char direction);
    bool moveToNeighbor(cell *neighbor);
    bool initializeCharacter(cell *currentCell);


};

character::~character()
{
}

#endif