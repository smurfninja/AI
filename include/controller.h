#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "grid.h"

class Controller{
  public:
   Controller();
   Controller(Grid *);
   void find();
  private:
   Grid * _model;
   Grid * _answer = new Grid();
   
};

#endif
