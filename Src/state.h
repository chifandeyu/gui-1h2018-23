#ifndef STATE_H
#define STATE_H

#include "ship.h"
#include "object.h"
#include "bullet.h"

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <ctime>
#include <ratio>
#include <chrono>

struct State {

  typedef std::chrono::high_resolution_clock::time_point time;
  typedef std::shared_ptr<Ship> ship_ptr;
  typedef std::shared_ptr<Object> object_ptr;
  typedef std::vector<object_ptr> object_vec;
  typedef std::shared_ptr<Bullet> bullet_ptr;
  typedef std::vector<bullet_ptr> bullet_vec;

  State();

  virtual ~State() {
  }

  // Флаги состояний игры
  std::map<std::string, bool> flags;

  //Уровнь
  int level;

  // Счёт в текущей игре
  int score;

  // Количество жизней в  текущей игре
  int life;

  ship_ptr ship;
  bullet_vec bullets;
  object_vec objects;

  // Маштаб игры
  int scale;

  // Размеры поля
  int height, width;

  // Время последнего выстрела
  time timeShot;

 private:

  const std::vector<std::string> _keys;

  void insertFlagsFalse(std::vector<std::string> keys);
};

#endif // STATE_H
