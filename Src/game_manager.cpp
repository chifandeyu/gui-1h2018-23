#include "game_manager.h"
#include "state.h"

void GameManager::update() {
  updateShip(_state->ship, _state);
  updateBullets(_state->bullets, _state);
  updateObjects(_state->objects, _state);
}

inline void GameManager::updateShip(State::ship_ptr ship, GameManager::state_ptr state) {
  ship->update();
}

void GameManager::updateBullets(State::object_vec bullets, GameManager::state_ptr state) {
  for (auto bullet : bullets) {
    bullet->update();
  }
}

void GameManager::updateObjects(State::object_vec objects, GameManager::state_ptr state) {
  for (auto object : objects) {
    object->update();
  }
}

