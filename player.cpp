#include "player.h"
#include "map.h"
#include "cell.h"

#include <iostream>

player::player(map* mainMap, int x, int y, char who){
  this->current_x = x;
  this->current_y = y;
  this->occupiedMap = mainMap;
  this->who = who;
  initializeCharacter(mainMap->getCell(x, y));
}

int player::move(char direction,char who){

    cell *nextCell = nullptr;
    cell *pastCell = nullptr;
    cout<<"player at "<<this->current_x<<" , "<<this->current_y<<endl;
    pastCell = occupiedMap->getCell(this->current_x, this->current_y);
    if(direction == 'n'){
      if(this->current_y - 1 != -1){
      nextCell = this->occupiedMap->getCell(this->current_x, this->current_y--);
      } else{
         this->current_y++;
        return 0;
      }
    }
    if(direction == 'e'){
      if(this->current_x + 1 != WIDTH){
      nextCell = this->occupiedMap->getCell(this->current_x++, this->current_y);
      }else{
        this->current_x--;
        return 0;
      }
    }
    if(direction == 's'){
      if(this->current_y + 1 != HEIGHT){
      nextCell = this->occupiedMap->getCell(this->current_x, this->current_y ++);
      } else{
         this->current_y--;
        return 0;
      }
    }
    if(direction == 'w'){
      if(this->current_x- 1 != -1){
      nextCell = this->occupiedMap->getCell(this->current_x--, this->current_y);
      }  else{
         this->current_x++;
        return 0;
      }
    }
  
    int returnVal = nextCell->enter(who,this);
    pastCell->vacate();
    return returnVal;
}

bool player::initializeCharacter(cell *currentCell){
    currentCell->enter(this->who);
    return true;
}