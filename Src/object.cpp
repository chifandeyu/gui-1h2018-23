#define _USE_MATH_DEFINES

#include "object.h"
#include <cmath>


inline Object::point Object::getPos() const{
  return _pos;
}

inline qreal Object::getSpeedVal() const {
  return _speedVal;
}

inline qreal Object::getSpeedAngle() const {
  return _speedAngle;
}

void Object::setPos(Object::point pos) {
  _pos = pos;
}

void Object::setSpeedAngle(qreal angle) {
  _speedAngle = normAngle(angle);
}

inline void Object::update() {
  updatePos();
}

void Object::updatePos() {
  qreal angle = getSpeedAngle();
  qreal val = getSpeedVal();
  Object::point dPos = Object::point(val*cos(angle), val*sin(angle));

  setPos(getPos()+dPos);
}


qreal Object::normAngle(qreal angle) {
  auto new_angle = std::fmod(angle, 2 * M_PI);
  if (new_angle < 0) {
    new_angle += 2*M_PI;
  }
  return new_angle;
}
