#ifndef _cell_h
#define _cell_h

#include "player.h"
#include <string>
using namespace std;

class cell{
private:
    /* data */
    char type;
    char prevtype;
    int x;
    int y;
    bool hasWeapon;
    bool isHazard;

public:
    cell(char c, int x, int y);

  char display();
  // robot enters location
  bool enter(char who,player* c);
  void enter(char who);
  // robot leaves location
  void vacate();

  bool triggerArrow(char direction,player* c);

  int getX();
  int getY();
};

#endif