#include "controller.h"

Controller::Controller(State* state)
  :_manager(state) {
}

void Controller::update() {
  _manager.update();
}
