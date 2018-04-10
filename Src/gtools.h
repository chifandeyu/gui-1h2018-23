#ifndef GTOOLS
#define GTOOLS

#include <chrono>
#include <random>


namespace gTools {
  extern double SHIP_DEF_ACC_VAL;
  extern double SHIP_DEF_ROTATE_ANGLE_SPEED;
  extern double SHIP_DEF_MAX_SPEED;
  extern double SHIP_DEF_LIFE;
  extern double STRIKE_BREAK;
  extern double BULLET_MASS;


  typedef std::chrono::high_resolution_clock::time_point time;

  double random(double left, double right);

  int timeLeft(time t);
}


#endif // G_TOOLS_H
