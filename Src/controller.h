#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game_manager.h"
#include "state.h"

class Controller {
 private:

  GameManager _manager;

 public:

  Controller(State* state);

  void update();

};

#endif // CONTROLLER_H
