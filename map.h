#ifndef _map_h
#define _map_h
#include <cell.h>

static const int WIDTH = 9;
static const int HEIGHT = 9;

class map
{
private:
    /* data */
      cell *cells[HEIGHT][WIDTH];
public:
    map(/* args */);
    ~map();

  void load();
  // write the full map to cout
  void write();

  cell* getCell(int x, int y);
};

map::map(/* args */)
{
}

map::~map()
{
}


#endif