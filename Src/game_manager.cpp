#define _USE_MATH_DEFINES

#include "game_manager.h"
#include "state.h"
#include <ctime>
#include <cmath>
#include <QPoint>
#include <algorithm>

void GameManager::initGame() {
  _state->width = 800;
  _state->height = 600;
  _state->scale = 8;
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
    x = state->width / 2 * cos(t) + state->width / 2;
    y = state->height / 2 * sin(t) + state->height / 2;
    speedVal = 2 + (rand()%10000)/10000.0 * (3-2);
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
  updateCollision(_state);
}

inline void GameManager::updateShip(State::ship_ptr ship, GameManager::state_ptr state) {
  updateObject(ship, state);
}

void GameManager::updateBullets(State::bullet_vec bullets, GameManager::state_ptr state) {
  for (int i = 0; i < state->bullets.size(); i++) {
    updateObject(state->bullets[i], state);
    if (state->bullets[i]->getLifeTime() <= 0) {
      state->bullets.erase(state->bullets.begin()+i);
      i--;
    }
  }
}

void GameManager::updateObjects(State::object_vec objects, GameManager::state_ptr state) {
  for (auto object : objects) {
    updateObject(object, state);
  }
}

void GameManager::updateObject(State::object_ptr object, GameManager::state_ptr state) {
  object->update();

  qreal x = object->getPos().x();
  qreal y = object->getPos().y();

  x = std::fmod(x, state->width);
  y = std::fmod(y, state->height);

  if (x < 0)
    x += state->width;

  if (y < 0)
    y += state->height;

  object->setPos(x, y);
}

void GameManager::turnOnAcc() {
  _state->ship->turnOnAcc();
}

void GameManager::turnOnRotateLeft() {
  _state->ship->setRotateDir(LEFT);
}

void GameManager::turnOnRotateRight() {
  _state->ship->setRotateDir(RIGHT);
}

void GameManager::turnOffAcc() {
  _state->ship->turnOffAcc();
}

void GameManager::turnOffRotateLeft() {
  _state->ship->setRotateDir(STAY);
}

void GameManager::turnOffRotateRight() {
  _state->ship->setRotateDir(STAY);
}


void GameManager::strike() {
  auto ship = _state->ship;
  auto pos = ship->getPos();
  auto angle = ship->getAccAngle();

  auto bullet = _builder.makeBullet(pos.x()+cos(angle),
                                    pos.y()+sin(angle));

  bullet->setSpeedVal(4);
  bullet->setSpeedAngle(ship->getAccAngle());

  _state->bullets.push_back(std::dynamic_pointer_cast<Bullet>(bullet));

}

void GameManager::updateCollision(GameManager::state_ptr state) {
  State::ship_ptr ship = state->ship;
  State::object_vec objects = state->objects;
  State::bullet_vec bullets = state->bullets;
  State::object_vec newAsteroids;

  if (std::any_of(objects.begin(), objects.end(),
                  [this, ship](auto object){
                    return isCollision(ship, object);
                  }))
    breakShip();

  auto f = [this, bullets, &newAsteroids](State::object_ptr o){
    for (int i = 0; i < bullets.size(); i++) {
      if (isCollision(bullets[i], o)) {
        destroyBullet(i);
        breakAsteroid(newAsteroids, o);
        return true;
      }
    }
    return false;
  };

  state->objects.erase(std::remove_if(state->objects.begin(),
                                      state->objects.end(),
                                      f),
                       state->objects.end());

  state->objects.insert(state->objects.end(),
                        newAsteroids.begin(),
                        newAsteroids.end());
}

void GameManager::breakShip() {
  _state->ship->setPos(Object::point(55,55));
}

void GameManager::destroyBullet(int i) {
  _state->bullets.erase(_state->bullets.begin()+i);
}

void GameManager::breakAsteroid(State::object_vec &newAsteroids, State::object_ptr object) {
  if (object->getSize() > 1.5) {
    State::object_ptr ast1 = _builder.makeAsteroid(object->getPos().x(),
                                                   object->getPos().y(),
                                                   object->getSize()-1);
    newAsteroids.push_back(ast1);
    newAsteroids.push_back(_builder.makeAsteroid(object->getPos().x()-22, object->getPos().y(), object->getSize()-1));
  }
}

bool GameManager::isCollision(State::object_ptr o1, State::object_ptr o2) {
  Object::point o = (o1->getPos())-(o2->getPos());
  return sqrt(o.x()*o.x() + o.y() * o.y()) < (o1->getSize()+o2->getSize())*_state->scale;
}
