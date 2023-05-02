#include "map.h"
#include "cell.h"
#include "character.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

character::character(map* map, int startx, int starty,char who){
    this->occupiedMap = map;
    this->current_x = startx;
    this->current_y = starty;
    this->who = who;

    initializeCharacter(map->getCell(startx, starty));
}

bool character::move(){
    cell *nextCell = nullptr;
     srand (time(NULL));
    int direction  = rand()%4;
    if(direction == 1){
      if(this->current_y - 1 != -1){
      nextCell = this->occupiedMap->getCell(this->current_x, this->current_y -= 1);
      } 
    }
    if(direction == 2){
      if(this->current_x + 1 != WIDTH){
      nextCell = this->occupiedMap->getCell(this->current_x += 1, this->current_y);
      }
    }
    if(direction == 3){
      if(this->current_y + 1 != HEIGHT){
      nextCell = this->occupiedMap->getCell(this->current_x, this->current_y += 1);
      }
    }
    else{
      if(this->current_x- 1 != -1){
      nextCell = this->occupiedMap->getCell(this->current_x -= 1, this->current_y);
      } 
    }
    if(nextCell->display()!='P'){
       occupiedMap->getCell(this->current_x, this->current_y)->vacate();
        nextCell->enter(this->who);
        return true;
    }else{
      return false;
    }
}


bool character::initializeCharacter(cell *currentCell){
    currentCell->enter(this->who);
    return true;
}