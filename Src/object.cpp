#define _USE_MATH_DEFINES

#include "object.h"
#include <QPoint>
#include <cmath>


inline QPoint Object::getPos() const{
  return _pos;
}

inline double Object::getSpeedVal() const {
  return _speedVal;
}

inline double Object::getSpeedAngle() const {
  return _speedAngle;
}

inline dirType Object::getRotateDir() const {
  return _rotateDir;
}

inline double Object::getRotateAngleSpeed() const {
  return _rotateAngleSpeed;
}

inline void Object::setPos(QPoint pos) {
  _pos = pos;
}

inline void Object::setPos(int x, int y) {
  _pos = QPoint(x, y);
}


inline void Object::setSpeedAngle(double angle) {
  _speedAngle = normAngle(angle);
}

inline void Object::setRotateDir(dirType dir) {
  _rotateDir = dir;
}

inline void Object::setRotateAngleSpeed(double speed) {
  _rotateAngleSpeed = speed;
}

inline void Object::update() {
  updatePos();
  updateRotate();
}

void Object::updatePos() {
  double angle = getSpeedAngle();
  double val = getSpeedVal();
  QPoint dPos = QPoint(val*cos(angle), val*sin(angle));

  setPos(getPos()+dPos);
}

void Object::updateRotate() {
  auto dir = getRotateDir();
  auto rotateSpeed = getRotateAngleSpeed();
  auto dAngle = dir ? -rotateSpeed : rotateSpeed;

  setSpeedAngle(normAngle(getSpeedAngle()+dAngle));
}

double Object::normAngle(double angle) {
  auto new_angle = angle - ((int) angle/M_PI) * M_PI;
  return new_angle > 0 ? new_angle : new_angle + M_PI;
}
