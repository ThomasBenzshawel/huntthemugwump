#include "cell.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


cell::cell(char c, int x, int y){
    this->type = c;
    this->x = x;
    this->y = y;
    this->prevtype='^';

    if(c == 'A' || '#'){
        this->isHazard = true;
    } else if(c == 'B' || 'S'){
        this->hasWeapon = true;
    }
}

  char cell::display(){
    return type;
  }
  void cell::enter(char who){
    this->prevtype=this->type;
    this->type=who;
  }
  // robot enters location
  bool cell::enter(char who,player* c){
    this->prevtype=this->type;
    this->type=who;
    if(prevtype=='>'||prevtype=='<'||prevtype=='^'||prevtype=='v'){
      return triggerArrow(prevtype,c);
    }else if(prevtype=='#'){
      cout<<"You hit a snare trap, you lose your turn";
      return false;
    }else if(prevtype=='B'){
      cout<<"You find a chest with a Bomb in it, use it carefully";
      c->numBomb++;
      prevtype='*';
    }else if(prevtype=='S'){
      srand (time(NULL));
      int type = rand()%2;
      if(type==1){
        cout<<"You find a chest with a flimsy sheild in it, this should be good to block any projectiles"<<endl;
        if(!c->hasTrapSheild){
          c->hasTrapSheild=true;
          prevtype='*';
        }else{
        cout<<"You already have one of these sheilds, but you should be able to come back for it"<<endl;
        }
      }else{
        cout<<"You find a chest with a sturdy sheild in it, this should be good to block atacks form the wumpus"<<endl;
        if(!c->hasWumpSheild){
          c->hasWumpSheild=true;
          prevtype='*';
        }else{
        cout<<"You already have one of these sheilds, but you should be able to come back for it"<<endl;
        }
      }
    
    }
    return true;
  }
  // robot leaves location
  void cell::vacate(){
    this->prevtype=this->type;
    this->prevtype='^';
  }

  int cell::getX(){
    return this-> x;
  }
  int cell::getY(){
    return this-> y;
  }

  bool cell::triggerArrow(char direction,player* c){
    cout<<"you reachec an arrow trap.Pick a direction to defend in a direction"<<endl;
    cout<<"Action: N)orth, S)outh, E)ast, W)est"<<endl;
    char input;
    cin>>input;
    if(direction=='<'&&(input=='W'||input=='w')){
      cout<<"you succesfully defended";
      return true;
    }else if(direction=='^'&&(input=='N'||input=='n')){
      cout<<"you succesfully defended";
      return true;
    }else if(direction=='>'&&(input=='E'||input=='e')){
      cout<<"you succesfully defended";
      return true;
    }else if(direction=='v'&&(input=='S'||input=='s')){
      cout<<"you succesfully defended";
      return true;
    }else{
      if(c->hasTrapSheild){
        c->hasTrapSheild=false;
        cout<<"Ouch,you get hit by the arrow trap but live thanks to your sheild"<<endl;
        cout<<"Your sheild gets destroyed"<<endl;
        return true;
      }else{
        c->isAlive=false;
        cout<<"Ouch, you get hit by the arrow trap"<<endl;
        return false;
      }
    }
    return true;
  };


