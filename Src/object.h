#ifndef OBJECT_H
#define OBJECT_H

#include <QPoint>
#include <vector>

enum dirType { LEFT = -1, STAY = 0, RIGHT = 1};

class Object {
public:
  #define DEF_R_A_SPEED 0.1

  Object(double x, double y,
         double speedAngle,
         double speedVal)
    :_pos(QPoint(x,y))
    ,_speedVal(speedVal)
    ,_speedAngle(speedAngle)
    ,_rotateDir(STAY)
    ,_rotateAngleSpeed(DEF_R_A_SPEED){
  }

 Object(double x, double y)
   :Object(x,y,0,0) {
  }

  Object()
    :Object(0,0,0,0) {
  }

  QPoint getPos() const;

  double getSpeedVal() const;

  double getSpeedAngle() const;

  dirType getRotateDir() const;

  double getRotateAngleSpeed() const;


  void setPos(QPoint pos);

  void setPos(int x, int y);

  void setSpeedVal(double val) {
    _speedVal = val;
  }

  void setSpeedAngle(double angle);

  void setRotateDir(dirType dir);

  void setRotateAngleSpeed(double speed);


  virtual void update();
protected:

  void updatePos();

  void updateRotate();

  double normAngle(double angle);



  std::vector<QPoint> _pointCloud;

  QPoint _pos;

  double _speedVal;
  double _speedAngle;

  dirType _rotateDir;
  double _rotateAngleSpeed;
};

#endif // OBJECT_H
