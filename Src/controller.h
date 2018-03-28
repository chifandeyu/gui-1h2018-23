#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game_manager.h"
#include "state.h"
#include <QKeyEvent>

class Controller {
 private:

  GameManager _manager;

 public:

  Controller(State* state);

  void update();

  void keyPressEvent(QKeyEvent *event);

  void keyReleaseEvent(QKeyEvent *event);

};

#endif // CONTROLLER_H
