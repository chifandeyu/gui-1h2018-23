#ifndef STATE_H
#define STATE_H

#include "ship.h"
#include "object.h"

#include <string>
#include <vector>
#include <map>
#include <memory>

struct State {

  State();

  virtual ~State() {
  }

  // Флаги состояний игры
  std::map<std::string, bool> flags;

  // Счёт в текущей игре
  int score;
  // Количество жизней в  текущей игре
  int life;

  std::shared_ptr<Ship> ship;
  std::vector<std::shared_ptr<Object>> bullets;
  std::vector<std::shared_ptr<Object>> objects;

 private:

  const std::vector<std::string> _keys;

  void insertFlagsFalse(std::vector<std::string> keys);
};

#endif // STATE_H
