#include "grid.h"
#include "controller.h"

int main(){
   Grid *g = new Grid();
   Controller c = Controller(g);
   c.find();
   return 0;
}
