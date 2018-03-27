#include "grid.h"

Grid::Grid(){
   for (int x = 0; x < MAX_SIZE; x++)
      for (int y = 0; y < MAX_SIZE; y++)
	 for (int z = 0; z < MAX_SIZE; z++){
	    _grid[x][y][z] = z;
	 }
   int count = 1;
   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++){
	 _box[i][j]=count;
	 count ++;
      }
}


int Grid::getValue(int x, int y){
   return _grid[x][y][0];
}

void Grid::add(int x, int y, int value){
   assert(value > 1 || value < 9);
   _grid[x][y][0] = value;
}

bool Grid::checkRow(int x){
   for (int i = 0; i < MAX_SIZE; i ++){
      if(_grid[x][i][0] > 9 ||_grid[x][i][0] < 0)
	 return false;
      for(int j = MAX_SIZE-1; j > i; j--)
	 if(_grid[x][i][0] != 0)
	    if(_grid[x][i][0] == _grid[x][j][0])
	       return false;
   }
   return true;
}

bool Grid::checkCol(int y){
   for (int i = 0; i < MAX_SIZE; i ++){
      if(_grid[i][y][0] > 9 ||_grid[i][y][0] < 0)
	 return false;
      for(int j = MAX_SIZE-1; j > i; j--)
	 if(_grid[i][y][0] != 0)
	   if(_grid[i][y][0] == _grid[j][y][0])
	    return false;
   }
   return true;
}

bool Grid::checkBox(int b){
   int box[MAX_SIZE];
   int minRow, maxRow, minCol, maxCol;
   
   if(b < 0)
      return false;
   if(b < 3)
      minRow = 0;
   if(b > 5)
      minRow = 6;
   if(b >= 3 && b <= 5)
      minRow = 3;
   if(b%3 == 1)
      minCol = 0;
   if(b%3 == 0)
      minCol = 6;
   if(b%3 == 2)
      minCol = 3;
   maxRow = minRow + 3;
   maxCol = minCol + 3;
   
   for(int i = 0; i < MAX_SIZE; i++)
      for(int m = minRow; m < maxRow; m++)
	 for(int n = minCol; n < maxCol; n++){
	    for(int x = 0; x < i; x++)
	       if (box[x] == box[i])
		  return false;
	    box[i] = _grid[m][n][0];
	 }
   return true;
}

void Grid::removeValue(int x, int y, int value){
   _grid[x][y][value] = 0;
}

bool Grid::filled(int x, int y){
   if (_grid[x][y][0] == 0)
      return false;
   return true;
}

int Grid::getBox(int x, int y){
   return _box[x%3][y&3];
}
