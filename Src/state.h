#ifndef STATE_H
#define STATE_H

#include "ship.h"
#include "object.h"

#include <string>
#include <vector>
#include <map>
#include <memory>

struct State {

  typedef std::shared_ptr<Ship> ship_ptr;
  typedef std::shared_ptr<Object> object_ptr;
  typedef std::vector<object_ptr> object_vec;

  State();

  virtual ~State() {
  }

  // Флаги состояний игры
  std::map<std::string, bool> flags;

  // Счёт в текущей игре
  int score;
  // Количество жизней в  текущей игре
  int life;

  ship_ptr ship;
  object_vec bullets;
  object_vec objects;

  // Маштаб игры
  int scale;
 private:

  const std::vector<std::string> _keys;

  void insertFlagsFalse(std::vector<std::string> keys);
};

#endif // STATE_H
