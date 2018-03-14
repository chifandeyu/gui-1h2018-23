#ifndef STATE_H
#define STATE_H

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
  std::vector<std::shared_ptr<Object>> objects;
};

#endif // STATE_H
