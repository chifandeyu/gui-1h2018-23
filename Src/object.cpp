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

inline dirType Object::getRotateDir() const {
  return _rotateDir;
}

inline qreal Object::getRotateAngleSpeed() const {
  return _rotateAngleSpeed;
}



inline void Object::setPos(Object::point pos) {
  _pos = pos;
}

inline void Object::setPos(qreal x, qreal y) {
  _pos = Object::point(x, y);
}


inline void Object::setSpeedAngle(qreal angle) {
  _speedAngle = normAngle(angle);
}

inline void Object::setRotateDir(dirType dir) {
  _rotateDir = dir;
}

inline void Object::setRotateAngleSpeed(qreal speed) {
  _rotateAngleSpeed = speed;
}


inline void Object::update() {
  updatePos();
  updateRotate();
}

void Object::updatePos() {
  qreal angle = getSpeedAngle();
  qreal val = getSpeedVal();
  Object::point dPos = Object::point(val*cos(angle), val*sin(angle));

  setPos(getPos()+dPos);
}

void Object::updateRotate() {
  auto dir = getRotateDir();
  auto rotateSpeed = getRotateAngleSpeed();
  auto dAngle = dir ? -rotateSpeed : rotateSpeed;

  setSpeedAngle(normAngle(getSpeedAngle()+dAngle));
}

qreal Object::normAngle(qreal angle) {
  auto new_angle = angle - ((int) angle/M_PI) * M_PI;
  return new_angle > 0 ? new_angle : new_angle + M_PI;
}
