#ifndef _cell_h
#define _cell_h

#include "player.h"
#include <string>
using namespace std;

class cell{
private:
    /* data */
    char type;
    char baseType;
    int x;
    int y;
    bool hasWeapon;
    bool isHazard;

public:
    cell(char c, int x, int y);

  char display();
  // robot enters location
  int enter(char who,player* c);
  void enter(char who,character* c);
  // robot leaves location
  void vacate();

  int triggerArrow(char direction,player* c);

  int getX();
  int getY();
};

#endif