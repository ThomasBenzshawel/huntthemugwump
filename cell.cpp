#include "cell.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


cell::cell(char c, int x, int y){
    this->type = c;
    this->x = x;
    this->y = y;

    if(c == 'A' || '#'){
        this->isHazard = true;
    } else if(c == 'B' || 'S'){
        this->hasWeapon = true;
    }
}

  char cell::display(){
    return type;
  }
  // robot enters location
  void cell::enter(){

  }
  // robot leaves location
  void cell::vacate(){

  }

  int cell::getX(){
    return this-> x;
  }
  int cell::getY(){
    return this-> y;
  }


