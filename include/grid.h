#ifndef GRID_H
#define GRID_H

#include <vector>
#include <assert.h>
const int MAX_SIZE = 9;

class Grid{
  public:
   Grid();
   int getValue(int, int);
   //add(x,y,value)
   void add(int, int, int);
   bool filled(int, int);
   bool checkRow(int);
   bool checkCol(int);
   //check box labels boxes 1-9 reading sudoku left to right top down
   bool checkBox(int);
   int getBox(int, int);
   void removeValue(int, int, int);
  private:
   int _box[3][3];
   int _grid[MAX_SIZE][MAX_SIZE][MAX_SIZE];
};

#endif
