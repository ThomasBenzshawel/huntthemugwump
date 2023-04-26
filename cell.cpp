#include "cell.h"
#include <iostream>
#include <string>
using namespace std;


cell::cell(char c, int x, int y){
    this->type = c;
    this->x = x;
    this->y = y;
}

  char cell::display(){
    return '?';
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


