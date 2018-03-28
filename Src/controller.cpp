#include "controller.h"
#include <QKeyEvent>

Controller::Controller(State* state)
  :_manager(state) {
}

void Controller::update() {
  _manager.update();
}

void Controller::keyPressEvent(QKeyEvent *event) {
  switch(event->key()) {
  default:
    break;
  }
}

void Controller::keyReleaseEvent(QKeyEvent *event) {
  switch(event->key()) {
  default:
    break;
  }
}
