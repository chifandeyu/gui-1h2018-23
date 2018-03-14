#include "state.h"
#include "ship.h"
#include "object.h"


State::State()
  :score(0)
  ,life(0) {
  flags.insert(std::pair<std::string, bool>
                ("isMenu", false));
  flags.insert(std::pair<std::string, bool>
                ("isPause", false));
  flags.insert(std::pair<std::string, bool>
                ("isGame", false));
  flags.insert(std::pair<std::string, bool>
                ("isGameOver", false));
}
