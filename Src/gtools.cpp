#include "gtools.h"


namespace gTools {
  double SHIP_DEF_ACC_VAL = 0.2;
  double SHIP_DEF_ROTATE_ANGLE_SPEED = 0.1;
  double SHIP_DEF_LIFE = 3;
  double STRIKE_BREAK = 200;
  double BULLET_MASS = 0.5;



  double random(double left, double right) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(left, right);
    return dist(gen);
  }

  int timeLeft(time t) {
    return std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now()
                                                      - t).count();
  }
}
