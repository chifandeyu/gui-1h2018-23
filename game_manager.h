#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <QPoint>
#include <memory>
#include "state.h"

class GameManager {
public:
  GameManager() {}

  void init() {}

  void start() {}

  State getState() const {return *_state;}

private:

  std::shared_ptr<State> _state;

};

#endif //GAME_MANAGER_H
