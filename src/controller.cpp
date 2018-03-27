#include "controller.h"

Controller::Controller(){
   _model = new Grid();
}

Controller::Controller(Grid * input){
   _model = input;
}
////LEFT OFF HERE
void Controller::find(){
   for (int i = 0; i < MAX_SIZE; i++){
      for (int j = 0; j < MAX_SIZE; j++){
	 if (_model->filled(i,j)){
	    break;
	 }
	 for (int k = k; k < MAX_SIZE; k++){
	    _answer->add(i,j,k);
	    if (_answer->checkRow(i) &&
		_answer->checkCol(j) &&
		_answer->checkBox(_answer->getBox(i,j)))
	       find();
	 }
      }
   }
}
