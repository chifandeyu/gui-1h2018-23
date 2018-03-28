#define _USE_MATH_DEFINES

#include "game_manager.h"
#include "state.h"
#include <ctime>
#include <cmath>
#include <QPoint>

void GameManager::initGame() {
  _state->level = 1;
  _state->score = 0;
  _state->life = 3;
  _state->ship = std::dynamic_pointer_cast<Ship>(_builder.makeShip(_state->width/2, _state->height/2));
  _state->objects = generateAsteroids(_state);
}

State::object_vec GameManager::generateAsteroids(state_ptr state) {
  srand(time(0));

  State::object_vec vec;
  int N = 3+state->level;

  double x, y, t, speedVal, speedAngle;

  for (int i = 0; i < N; i++) {
    t = (rand()%10000)/10000.0 * 2 * M_PI;
    x = state->width / 2 * cos(t);
    y = state->height / 2 * sin(t);
    speedVal = 0.5 + (rand()%10000)/10000.0 * (3-0.5);
    speedAngle = (rand()%10000)/10000.0 * 2 * M_PI;

    State::object_ptr a = _builder.makeAsteroid(x, y, 3);
    a->setSpeedVal(speedVal);
    a->setSpeedAngle(speedAngle);
    vec.push_back(a);
  }

  return vec;
}

void GameManager::update() {
  updateShip(_state->ship, _state);
  updateBullets(_state->bullets, _state);
  updateObjects(_state->objects, _state);
}

inline void GameManager::updateShip(State::ship_ptr ship, GameManager::state_ptr state) {
  updateObject(ship, state);
}

void GameManager::updateBullets(State::object_vec bullets, GameManager::state_ptr state) {
  for (auto bullet : bullets) {
    updateObject(bullet, state);
  }
}

void GameManager::updateObjects(State::object_vec objects, GameManager::state_ptr state) {
  for (auto object : objects) {
    updateObject(object, state);
  }
}

void GameManager::updateObject(State::object_ptr object, GameManager::state_ptr state) {
  object->update();

  qreal &x = object->getPos().rx();
  qreal &y = object->getPos().ry();

  x = std::fmod(x, state->width);
  y = std::fmod(y, state->height);
}

