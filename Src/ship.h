#ifndef SHIP_H
#define SHIP_H

#include "object.h"
#include <QImage>

class Ship : public Object {
 public:

  Ship(int x, int y)
    :Object(x, y)
    ,_accVal(0)
    ,_accAngle(0)
    ,_isAcc(false) {
    _pointCloud = Object::cloud({
          Object::point(0, 1),
          Object::point(1, -1),
          Object::point(0, -0.5),
          Object::point(-1, -1)});
  }

  Ship()
    :Object(0, 0) {
  }

  virtual ~Ship() {}

  qreal getAccVal() const;

  qreal getAccAngle() const;

  bool isAcc() const;


  void setAccdVal(qreal val);

  void setAccAngle(qreal angle);

  void turnOnAcc();

  void turnOffAcc();


  virtual void update();

 protected:

  void updateSpeed();

  qreal _accVal;
  qreal _accAngle;
  bool _isAcc;
};

#endif // SHIP_H
