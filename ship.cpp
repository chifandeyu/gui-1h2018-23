#define _USE_MATH_DEFINES

#include "ship.h"
#include <cmath>

qreal Ship::getAccVal() const {
  return _accVal;
}

qreal Ship::getAccAngle() const {
  return _accAngle;
}

inline dirType Ship::getRotateDir() const {
  return _rotateDir;
}

qreal Ship::getRotateAngleSpeed() const {
  return _rotateAngleSpeed;
}

bool Ship::isAcc() const {
  return _isAcc;
}

void Ship::setAccdVal(qreal val) {
  _accVal = val;
}

void Ship::setAccAngle(qreal angle) {
  _accAngle = normAngle(angle);
}

void Ship::setRotateDir(dirType dir) {
  _rotateDir = dir;
}

void Ship::setRotateAngleSpeed(qreal speed) {
  _rotateAngleSpeed = speed;
}

void Ship::turnOnAcc() {
  _isAcc = true;
}

void Ship::turnOffAcc() {
  _isAcc = false;
}

inline void Ship::update() {
  Object::update();
  updateSpeed();
  updateRotate();
}

void Ship::updateRotate() {
  auto dir = getRotateDir();

  if (dir != STAY) {
      auto rotateAcc = getAccAngle();
      auto dAngle = dir == LEFT ? -getRotateAngleSpeed() : getRotateAngleSpeed();

      setAccAngle(normAngle(rotateAcc+dAngle));
  }
}

void Ship::updateSpeed() {
  if (isAcc()) {
      qreal accAngle = getAccAngle();
      qreal accVal = getAccVal();
      qreal speedAngle = getSpeedAngle();
      qreal speedVal = getSpeedVal();

      qreal x = accVal * cos(accAngle) + speedVal * cos(speedAngle);
      qreal y = accVal * sin(accAngle) + speedVal * sin(speedAngle);


      qreal newSpeedVal = std::fmod(sqrt(pow(x, 2) + pow(y, 2)),
                                    gTools::SHIP_DEF_MAX_SPEED);
      qreal newSpeedAngle = atan2(y,x);

      setSpeedAngle(newSpeedAngle);
      setSpeedVal(newSpeedVal);
    }
}
