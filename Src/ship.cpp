#define _USE_MATH_DEFINES

#include "ship.h"
#include <cmath>

inline double Ship::getAccVal() const {
  return _accVal;
}

inline double Ship::getAccAngle() const {
  return _accAngle;
}

inline bool Ship::isAcc() const {
  return _isAcc;
}

inline void Ship::setAccdVal(double val) {
  _accVal = val;
}

inline void Ship::setAccAngle(double angle) {
  _accAngle = normAngle(angle);
}

inline void Ship::turnOnAcc() {
  _isAcc = true;
}

inline void Ship::turnOffAcc() {
  _isAcc = false;
}

inline void Ship::update() {
  Object::update();
  updateSpeed();
}

void Ship::updateSpeed() {
  double accAngle = getAccAngle();
  double accVal = getAccVal();
  double speedAngle = getSpeedAngle();
  double speedVal = getSpeedVal();

  double x = accVal * cos(accAngle) + speedVal * cos(speedAngle);
  double y = accVal * sin(accAngle) + speedVal * sin(speedAngle);


  double newSpeedVal = sqrt(pow(x, 2) + pow(y, 2));
  double newSpeedAngle = atan2(y,x)+M_PI;

  setSpeedAngle(newSpeedAngle);
  setSpeedVal(newSpeedVal);
}
