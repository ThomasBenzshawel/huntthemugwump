#include "character.h"
#include "map.h"
#include "cell.h"

character::character(map *map, int startx, int starty){
    this->occupiedMap = map;
    this->current_x = startx;
    this->current_y = starty;

    initializeCharacter(map->getCell(startx, starty));
}

bool character::move(char direction){
    cell *nextCell = nullptr;

    if(direction == 'n'){
      if(this->current_y - 1 != -1){
      nextCell = this->occupiedMap->getCell(this->current_x, this->current_y -= 1);
      } 
    } else if(direction == 'e'){
      if(this->current_x + 1 != WIDTH){
      nextCell = this->occupiedMap->getCell(this->current_x += 1, this->current_y);
      }

    } else if(direction == 's'){
      if(this->current_y + 1 != HEIGHT){
      nextCell = this->occupiedMap->getCell(this->current_x, this->current_y += 1);
      }

    } else if(direction == 'w'){
      if(this->current_x- 1 != -1){
      nextCell = this->occupiedMap->getCell(this->current_x -= 1, this->current_y);
      } 
      occupiedMap->getCell(this->current_x, this->current_y)->vacate();
    return moveToNeighbor(nextCell);

    }
}

bool character::moveToNeighbor(cell *neighbor){
    neighbor->enter();
    return true;
}

bool character::initializeCharacter(cell *currentCell){
    moveToNeighbor(currentCell);
}