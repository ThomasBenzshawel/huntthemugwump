#include "map.h"
#include <iostream>
#include <string>
#include "cell.h"

  // initialize empty map
  map::map(){
    for(int i = 0; i < HEIGHT; i++){
      for(int j = 0; j < WIDTH; j++){
        cells[i][j] = nullptr;
      }
    }
  }

  void map::write(){
    for(int i = 0; i < HEIGHT + 1; i++){
      for(int j = 0; j < WIDTH + 1; j++){
        cout << cells[i-1][j-1]->display();
      }
      }
    }

  cell* map::getCell(int x, int y){
    return cells[y][x];
  }