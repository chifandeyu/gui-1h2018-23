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
  }

  Ship()
    :Object(0, 0) {
  }

  virtual ~Ship() {}

  double getAccVal() const;

  double getAccAngle() const;

  bool isAcc() const;


  void setAccdVal(double val);

  void setAccAngle(double angle);

  void turnOnAcc();

  void turnOffAcc();


  virtual void update();

 protected:

  void updateSpeed();

  double _accVal;
  double _accAngle;
  bool _isAcc;
};

#endif // SHIP_H
