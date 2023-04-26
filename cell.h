#ifndef _cell_h
#define _cell_h

#include <string>
using namespace std;

class cell{
private:
    /* data */
    char type;
    int x;
    int y;
    bool hasWeapon;

public:
    cell(/* args */);
    cell(char c, int x, int y);

    ~cell();

  char display();
  // robot enters location
  void enter();
  // robot leaves location
  void vacate();

  int getX();
  int getY();
};

#endif