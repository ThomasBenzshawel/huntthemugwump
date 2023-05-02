#include "player.h"
#include "map.h"
#include "cell.h"

#include <iostream>

player::player(map* mainMap, int x, int y,char who) : character(mainMap, x, y,who){}

bool player::move(char direction,char who){
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
    occupiedMap->getCell(this->current_x, this->current_y)->vacate();
    return nextCell->enter(who,this);
}
