#include "map.h"
#include "cell.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;



  // initialize empty map
  map::map(){
    for(int i = 0; i < HEIGHT; i++){
      for(int j = 0; j < WIDTH; j++){
        cells[j][i] = nullptr;
      }
    }
  }

  void map::write(){
    for(int i = 0; i < HEIGHT; i++){
      for(int j = 0; j < WIDTH; j++){
        cout << cells[j][i]->display();
      }
       cout << endl;
      }
    }

  cell* map::getCell(int x, int y){
    return cells[x][y];
  }

  //triggers the bomb
  //return -1=player dies
  //return 1=wumpus dies
  //return 0 nothing happens
  int map::blowUp(int x,int y){
      if(cells[x][y]->display()=='W'){
        return 1;
      }else if(cells[x][y]->display()=='P'){
        return -1;
      }
      cells[x][y]=new cell('*',x,y);
      if(x+1!=WIDTH){
         if(cells[x+1][y]->display()=='W'){
        return 1;
      }else if(cells[x+1][y]->display()=='P'){
        return -1;
      }
      cells[x+1][y]=new cell('*',x,y);
      }
      if(!x-1<0){
         if(cells[x-1][y]->display()=='W'){
        return 1;
      }else if(cells[x-1][y]->display()=='P'){
        return -1;
      }
      cells[x-1][y]=new cell('*',x,y);
      }
      if(y+1!=HEIGHT){
         if(cells[x][y+1]->display()=='W'){
        return 1;
      }else if(cells[x][y+1]->display()=='P'){
        return -1;
      }
      cells[x][y+1]=new cell('*',x,y);
      }
       if(!y-1<0){
         if(cells[x][y-1]->display()=='W'){
        return 1;
      }else if(cells[x][y-1]->display()=='P'){
        return -1;
      }
      cells[x][y-1]=new cell('*',x,y);
      }
      return 0;
  }
  //loads the map
  void map::load(int numWeapons, int numHazards){
    srand (time(NULL));

    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
          cell *newCell = new cell('.', j, i);
          cells[j][i] = newCell;
      }
    }
 
    for(int i = 0; i < numHazards; i++){
      int random_x = rand() % HEIGHT + 1;
      int random_y = rand() % WIDTH + 1;
      if(rand() % 3 + 1 == 1){
        cell *newCell = new cell('#', random_x, random_y);
        cells[random_x][random_y] = newCell;
      } else {
        int type = rand()%4;
        if(type==1){
          cell *newCell = new cell('>', random_x, random_y);
          cells[random_x][random_y] = newCell;   
        }else if(type==2){
          cell *newCell = new cell('<', random_x, random_y);
          cells[random_x][random_y] = newCell;   
        }else if(type==3){
          cell *newCell = new cell('^', random_x, random_y);
          cells[random_x][random_y] = newCell;   
        }else{
          cell *newCell = new cell('v', random_x, random_y);
          cells[random_x][random_y] = newCell;   
        }
      }
    }

    for(int i = 0; i < numWeapons; i++){
      int random_x = rand() % HEIGHT + 1;
      int random_y = rand() % WIDTH + 1;
    
      if(rand() % 3 + 1 == 1){
        cell *newCell = new cell('B', random_x, random_y);
        cells[random_x][random_y] = newCell;
      
      } else {
        cell *newCell = new cell('S', random_x, random_y);
        cells[random_x][random_y] = newCell;   
      
      }
     
    }
   
    
  }
  //checks if the wumpus is near
  int map::WumpusNear(){
    int WumpusCordX=-1;
    int WumpusCordY=-1;
    int PlayerCordX=-1;
    int PlayerCordY=-1;
     for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
        if(cells[j][i]->display() == 'P'){
          PlayerCordX=j;
          PlayerCordY=i;
          cout<< "According to dom, Player at: " << j << "," << i <<endl;
        }else if(cells[j][i]->display() == 'W'){
          WumpusCordX=j;
          WumpusCordY=i;
          cout<< "According to dom, Wumpus at: " << j << "," << i <<endl;
        }
      }
    }
    if(WumpusCordX-1==PlayerCordX){
      //to the west of the player
      return 1;
    }else if(WumpusCordX+1==PlayerCordX){
      //to the east of the player
      return 2;
    }else if(WumpusCordY-1==PlayerCordX){
      //to the noth of the player
      return 3;
    }else if(WumpusCordY+1==PlayerCordY){
      //to the south of the player
      return 4;
    }
    //not near
    return -1;
  }