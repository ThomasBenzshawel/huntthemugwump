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
   occupiedMap->getCell(this->current_x, this->current_y)->vacate();
   int x = this->current_x;
   int y = this->current_y;
    cell *nextCell = nullptr;
     srand (time(NULL));
    int direction  = rand()%4;
    if(direction == 1){
      if(this->current_y - 1 >= 1){
      nextCell = this->occupiedMap->getCell(this->current_x, this->current_y - 1);
      } else{
        return false;
      }
    }
    if(direction == 2){
      if(this->current_x + 1 < WIDTH){
      nextCell = this->occupiedMap->getCell(this->current_x + 1, this->current_y);
      }else{
        return false;
      }
    }
    if(direction == 3){
      if(this->current_y + 1 < HEIGHT){
      nextCell = this->occupiedMap->getCell(this->current_x, this->current_y + 1);
      }else{
        return false;
      }
    }
    else{
      if(this->current_x- 1 > 0){
        nextCell = this->occupiedMap->getCell(this->current_x - 1, this->current_y);
      } else{
        return false;
      }
    }
    if(nextCell->display()!='P'){
      this->current_x = nextCell->getX();
      this->current_y = nextCell->getY();
      cout << this->current_x << ", " << this->current_y << endl;

        nextCell->enter(this->who);
        return true;
    }else{
      this->occupiedMap->getCell(x,y)->enter(this->who);
      return false;
    }
}


bool character::initializeCharacter(cell *currentCell){
    currentCell->enter(this->who);
    return true;
}