#include "map.h"
#include "cell.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>



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

  void map::load(int numWeapons, int numHazards){
    srand (time(NULL));

    for(int i = 0; i < numHazards; i++){
      int random_x = rand() % HEIGHT + 1;
      int random_y = rand() % WIDTH + 1;

      if(rand() % 3 + 1 == 1){
        cell *newCell = new cell('#', random_x, random_y);
        cells[random_x][random_y] = newCell;
      } else {
        cell *newCell = new cell('A', random_x, random_y);
        cells[random_x][random_y] = newCell;   
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

      for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
        if(cells[j][i] == nullptr){
          cell *newCell = new cell('.', random_x, random_y);
          cells[j][i] = newCell;
        }
      }
    }

    }

    cout<<"Map loaded";
  }