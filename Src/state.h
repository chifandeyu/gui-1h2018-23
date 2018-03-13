#ifndef STATE_H
#define STATE_H

#include <string>
#include <vector>
#include <map>

class State {
 public:

  State();

  virtual ~State() {
  }

 private:


  std::map<std::string, bool> _flags;

  int _score;

  Ship _ship;
  std::vector<std::shared_ptr<Object>> _objects;
};

#endif // STATE_H
