#define _USE_MATH_DEFINES

#include "ship.h"
#include <cmath>

inline qreal Ship::getAccVal() const {
  return _accVal;
}

inline qreal Ship::getAccAngle() const {
  return _accAngle;
}

inline bool Ship::isAcc() const {
  return _isAcc;
}

inline void Ship::setAccdVal(qreal val) {
  _accVal = val;
}

inline void Ship::setAccAngle(qreal angle) {
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
  qreal accAngle = getAccAngle();
  qreal accVal = getAccVal();
  qreal speedAngle = getSpeedAngle();
  qreal speedVal = getSpeedVal();

  qreal x = accVal * cos(accAngle) + speedVal * cos(speedAngle);
  qreal y = accVal * sin(accAngle) + speedVal * sin(speedAngle);


  qreal newSpeedVal = sqrt(pow(x, 2) + pow(y, 2));
  qreal newSpeedAngle = atan2(y,x)+M_PI;

  setSpeedAngle(newSpeedAngle);
  setSpeedVal(newSpeedVal);
}
