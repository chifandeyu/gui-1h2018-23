#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game_manager.h"
#include "state.h"
#include <QKeyEvent>

class Controller : public QObject {
 private:

  GameManager _manager;

 public:

  Controller(State* state);

  void update();

  void keyPressEvent(QKeyEvent *event);

  void keyReleaseEvent(QKeyEvent *event);

  void startGame();

  void resize(int width, int height);

};

#endif // CONTROLLER_H
