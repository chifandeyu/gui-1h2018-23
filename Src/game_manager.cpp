#define _USE_MATH_DEFINES

#include "game_manager.h"
#include "ship.h"
#include "state.h"
#include "gtools.h"
#include <ctime>
#include <cmath>
#include <QPoint>
#include <algorithm>

GameManager::GameManager(State *state)
    :_state(state)
    {
    initGame();
}

void GameManager::initGame() {
    _state->timeShot = std::chrono::high_resolution_clock::now();
    _state->dethTime = std::chrono::high_resolution_clock::now();
  _state->scale = 9;
  _state->level = 1;
  _state->score = 0;
  _state->life = 3;
  _state->ship = std::dynamic_pointer_cast<Ship>(_builder.makeShip(_state->width/2, _state->height/2));
  _state->objects = generateAsteroids(_state);
  _state->bullets.erase(_state->bullets.begin(),
                        _state->bullets.end());
  _state->flags.at("isGameOver") = false;
}

void GameManager::nextLevel() {
  _state->level++;
  _state->objects = generateAsteroids(_state);
  _state->bullets.erase(_state->bullets.begin(),
                        _state->bullets.end());
  _state->ship->setSpeedVal(0);
  _state->ship->setPos(Object::point(_state->width/2, _state->height/2));
}

State::object_vec GameManager::generateAsteroids(state_ptr state) {
  srand(time(0));

  State::object_vec vec;
  int N = 3+state->level;

  double x, y, t, speedVal, speedAngle;

  for (int i = 0; i < N; i++) {
    t = gTools::random(0, 2 * M_PI);
    x = state->width / 2 * cos(t) + state->width / 2;
    y = state->height / 2 * sin(t) + state->height / 2;
    speedVal = gTools::random(2, 3)+std::pow(2,state->level-1);
    speedAngle = gTools::random(0, 2 * M_PI);

    State::object_ptr a = _builder.makeAsteroid(x, y, 3);
    a->setSpeedVal(speedVal);
    a->setSpeedAngle(speedAngle);
    vec.push_back(a);
  }

  return vec;
}

void GameManager::update() {
  if (_state->objects.size() == 0) {
    nextLevel();
  } else {
    updateShip(_state->ship, _state);
    updateBullets(_state->bullets, _state);
    updateObjects(_state->objects, _state);
    updateCollision(_state);
  }
}

void GameManager::updateShip(State::ship_ptr ship, GameManager::state_ptr state) {
  if (_state->flags.at("isGameOver")) {
    return;
  }
  if (_state->flags.at("shipIsDeth")) {
    if (gTools::timeLeft(_state->dethTime) > gTools::DEATH_BREAK) {
      _state->flags.at("shipIsDeth") = false;
    }
  } else {
    updateObject(ship, state);
  }
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
//      std::shared_ptr <QMediaPlayer>_soundPlayer (new QMediaPlayer());
//      _soundPlayer->setMedia(QUrl("qrc:/sound/thrust.wav"));
//      // play bulletsound
//            if (_soundPlayer->state() == QMediaPlayer::PlayingState){
//                _soundPlayer->setPosition(0);
//            }
//            else if (_soundPlayer->state() == QMediaPlayer::StoppedState){
//                _soundPlayer->play();
//            }
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

  if (_state->bullets.size() < 6
      && !(_state->flags.at("shipIsDeth"))
      && (gTools::timeLeft(_state->timeShot) > gTools::STRIKE_BREAK)) {
    _state->timeShot = std::chrono::high_resolution_clock::now();
    auto ship = _state->ship;
    auto pos = ship->getPos();
    auto angle = ship->getAccAngle();

    auto bullet = _builder.makeBullet(pos.x()+cos(angle),
                                      pos.y()+sin(angle));

    bullet->setSpeedVal(10);
    bullet->setSpeedAngle(ship->getAccAngle());

    _state->bullets.push_back(std::dynamic_pointer_cast<Bullet>(bullet));
//    QMediaPlayer *_soundPlayer= new QMediaPlayer();
//    _soundPlayer->setMedia(QUrl("qrc:/sound/fire.wav"));
//    // play bulletsound
//          if (_soundPlayer->state() == QMediaPlayer::PlayingState){
//              _soundPlayer->setPosition(0);
//          }
//          else if (_soundPlayer->state() == QMediaPlayer::StoppedState){
//              _soundPlayer->play();
//          }
  }
}

void GameManager::updateCollision(GameManager::state_ptr state) {
  State::ship_ptr ship = state->ship;
  State::object_vec objects = state->objects;
  State::bullet_vec bullets = state->bullets;
  State::object_vec newAsteroids;

  if (!_state->flags.at("shipIsDeth") &&
      std::any_of(objects.begin(), objects.end(),
                  [this, ship](auto object){
                    return this->isCollision(ship, object);
                  }))
    breakShip();

  auto f = [this, &bullets, &newAsteroids](State::object_ptr o){
    for (int i = 0; i < bullets.size(); i++) {
      if (isCollision(bullets[i], o)) {
        bullets.erase(bullets.begin()+i);
        breakAsteroid(newAsteroids, o, bullets[i]);
        this->_state->score++;
        return true;
      }
    }
    return false;
  };

  state->objects.erase(std::remove_if(state->objects.begin(),
                                      state->objects.end(),
                                      f),
                       state->objects.end());

  state->bullets = bullets;
  state->objects.insert(state->objects.end(),
                        newAsteroids.begin(),
                        newAsteroids.end());
}

void GameManager::breakShip() {
//    QMediaPlayer *_soundPlayer= new QMediaPlayer();
//   _soundPlayer->setMedia(QUrl("qrc:/sound/bangLarge.wav"));
//   // play bulletsound
//         if (_soundPlayer->state() == QMediaPlayer::PlayingState){
//             _soundPlayer->setPosition(0);
//         }
//         else if (_soundPlayer->state() == QMediaPlayer::StoppedState){
//             _soundPlayer->play();
//         }
  _state->flags.at("shipIsDeth") = true;
  _state->dethTime = std::chrono::high_resolution_clock::now();
  _state->life--;
  _state->ship->setSpeedVal(0);
  _state->ship->setPos(Object::point(_state->width/2, _state->height/2));
  if (_state->life < 0) {
    gameOver();
  }
}

void GameManager::gameOver() {
  _state->flags.at("isGameOver") = true;
}

void GameManager::saveScore(QString name) {
  auto scores = gTools::readScore();
  scores.push_back(std::pair<QString, int>(name, _state->score));
  gTools::writeScore(scores);
}

void GameManager::destroyBullet(int i) {
  _state->bullets.erase(_state->bullets.begin()+i);
}

void GameManager::breakAsteroid(State::object_vec &newAsteroids, State::object_ptr object, State::object_ptr bullet) {
//    QMediaPlayer *_soundPlayer= new QMediaPlayer();
//   _soundPlayer->setMedia(QUrl("qrc:/sound/bangLarge.wav"));
//   // play bulletsound
//         if (_soundPlayer->state() == QMediaPlayer::PlayingState){
//             _soundPlayer->setPosition(0);
//         }
//         else if (_soundPlayer->state() == QMediaPlayer::StoppedState){
//             _soundPlayer->play();
//         }
  if (object->getSize() > 1.5) {

    int mass = gTools::BULLET_MASS;
    auto sum = sumVector(object->getSpeedAngle(), object->getSpeedVal(),
                         bullet->getSpeedAngle(), mass*bullet->getSpeedVal());
    State::object_ptr ast1 = _builder.makeAsteroid(object->getPos().x(),
                                                   object->getPos().y(),
                                                   object->getSize()-1);
    ast1->setSpeedAngle(Object().normAngle(sum.first-0.2));
    ast1->setSpeedVal(sum.second);

    State::object_ptr ast2 = _builder.makeAsteroid(object->getPos().x(),
                                                   object->getPos().y(),
                                                   object->getSize()-1);
    ast2->setSpeedAngle(Object().normAngle(sum.first+0.2));
    ast2->setSpeedVal(sum.second);

    newAsteroids.push_back(ast1);
    newAsteroids.push_back(ast2);

  }

}

bool GameManager::isCollision(State::object_ptr o1, State::object_ptr o2) {
  Object::point o = (o1->getPos())-(o2->getPos());
  return sqrt(o.x()*o.x() + o.y() * o.y()) < (o1->getSize()+o2->getSize())*_state->scale;
}

std::pair<qreal, qreal> GameManager::sumVector(qreal angle1, qreal val1, qreal angle2, qreal val2) {
  qreal x = val1 * cos(angle1) + val2 * cos(angle2);
  qreal y = val1 * sin(angle1) + val2 * sin(angle2);


  qreal newSpeedVal = sqrt(pow(x, 2) + pow(y, 2));
  qreal newSpeedAngle = atan2(y,x);


  return std::pair<qreal, qreal>(newSpeedAngle, newSpeedVal);
}

void GameManager::resize(int w, int h) {
  _state->width = w;
  _state->height = h;
}



