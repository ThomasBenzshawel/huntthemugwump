#include "map.h"
#include <iostream>
#include <string>
#include "cell.h"

  // initialize empty map
  map::map(){
    for(int i = 0; i < HEIGHT; i++){
      for(int j = 0; j < WIDTH; j++){
        cells[j][i] = nullptr;
      }
    }
  }

  void map::write(){
    for(int i = 0; i < HEIGHT + 1; i++){
      for(int j = 0; j < WIDTH + 1; j++){
        cout << cells[j-1][i-1]->display();
      }
      }
    }

  cell* map::getCell(int x, int y){
    return cells[x][y];
  }

  void map::load(){
    cout<<"Map loaded";
  }