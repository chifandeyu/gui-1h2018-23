#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <QPoint>
#include <memory>
#include "state.h"
#include "objectbuilder.h"

#include <typeinfo>

class GameManager {
public:

  typedef std::shared_ptr<State> state_ptr;

  GameManager(State* state)
    :_state(state) {
  }
  void initGame();

  State::object_vec generateAsteroids(state_ptr state);

  void update();

  void updateShip(State::ship_ptr ship, state_ptr state);

  void updateBullets(State::object_vec bullets, state_ptr state);

  void updateObjects(State::object_vec objects, state_ptr state);

  void updateObject(State::object_ptr object, state_ptr state);

private:

  state_ptr _state;

  ObjectBuilder _builder;
};

#endif //GAME_MANAGER_H
