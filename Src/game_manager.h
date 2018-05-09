#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <QPoint>
#include <memory>
#include "state.h"
#include "objectbuilder.h"
#include <QtMultimedia/QMediaPlayer>
#include <typeinfo>

class GameManager {
public:

  typedef std::shared_ptr<State> state_ptr;

  GameManager(State* state);
  void initGame();

  void nextLevel();

  State::object_vec generateAsteroids(state_ptr state);

  void update();

  void updateShip(State::ship_ptr ship, state_ptr state);

  void updateBullets(State::bullet_vec bullets, state_ptr state);

  void updateObjects(State::object_vec objects, state_ptr state);

  void updateObject(State::object_ptr object, state_ptr state);

  void turnOnAcc();
  void turnOnRotateLeft();
  void turnOnRotateRight();

  void turnOffAcc();
  void turnOffRotateLeft();
  void turnOffRotateRight();

  void strike();

  void updateCollision(GameManager::state_ptr state);

 void breakAsteroid(State::object_vec &newAsteroids, State::object_ptr object, State::object_ptr bullet);

 void gameOver();

 void saveScore(QString name);

 bool isCollision(State::object_ptr o1, State::object_ptr o2);

 void destroyBullet(int i);

 void breakShip();

 void resize(int width, int height);

private:

 std::pair<qreal, qreal> sumVector(qreal angle1, qreal val1, qreal angle2, qreal val2);

  state_ptr _state;

  ObjectBuilder _builder;



};

#endif //GAME_MANAGER_H
