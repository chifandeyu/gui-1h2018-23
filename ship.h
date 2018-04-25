#ifndef SHIP_H
#define SHIP_H

#include "object.h"
#include "gtools.h"
#include <QImage>

class Ship : public Object {
 public:

  Ship(int x, int y)
    :Object(x, y)
    ,_accVal(gTools::SHIP_DEF_ACC_VAL)
    ,_accAngle(0)
    ,_isAcc(false)
    ,_rotateDir(STAY)
    ,_rotateAngleSpeed(gTools::SHIP_DEF_ROTATE_ANGLE_SPEED){
    _pointCloud = Object::cloud({
          Object::point(1, 0),
          Object::point(-1, 1),
          Object::point(-0.5, 0),
          Object::point(-1, -1)});
  }

  Ship()
    :Object(0, 0) {
  }

  virtual ~Ship() {}

  qreal getAccVal() const;

  qreal getAccAngle() const;

  dirType getRotateDir() const;

  qreal getRotateAngleSpeed() const;

  bool isAcc() const;


  void setAccdVal(qreal val);

  void setAccAngle(qreal angle);

  void setRotateDir(dirType dir);

  void setRotateAngleSpeed(qreal speed);

  void turnOnAcc();

  void turnOffAcc();


  virtual void update();

 protected:

  void updateRotate();
  void updateSpeed();

  qreal _accVal;
  qreal _accAngle;
  bool _isAcc;

  dirType _rotateDir;
  qreal _rotateAngleSpeed;
};

#endif // SHIP_H
