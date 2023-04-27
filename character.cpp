#include "map.h"
#include "cell.h"
#include "character.h"
#include <iostream>

character::character(map* map, int startx, int starty){
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
    }

    if(direction == 'e'){
      if(this->current_x + 1 != WIDTH){
      nextCell = this->occupiedMap->getCell(this->current_x += 1, this->current_y);
      }
    }

    if(direction == 's'){
      if(this->current_y + 1 != HEIGHT){
      nextCell = this->occupiedMap->getCell(this->current_x, this->current_y += 1);
      }
    }

    if(direction == 'w'){
      if(this->current_x- 1 != -1){
      nextCell = this->occupiedMap->getCell(this->current_x -= 1, this->current_y);
      } 
    }
    return moveToNeighbor(nextCell);
    cout<< "got here";
}

bool character::moveToNeighbor(cell *neighbor){
    //neighbor->enter();
    cout<< this->current_x << ", " << this->current_y << endl;
    return true;
}

bool character::initializeCharacter(cell *currentCell){
    moveToNeighbor(currentCell);
}