#include "state.h"

void State::insertFlagsFalse(std::vector<std::string> keys) {
  for (auto k : keys) {
    flags.insert(std::pair<std::string, bool>
                 (k, false));
  }
}

State::State()
  :score(0)
  ,life(0)
  ,_keys(std::vector<std::string>
         ({"isMenu", "isPause",
           "isGame", "isGameOver"})){
  insertFlagsFalse(_keys);
}

