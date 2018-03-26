#ifndef OBJECT_H
#define OBJECT_H

#include<QPointF>
#include <utility>
#include <vector>

enum dirType { LEFT = -1, STAY = 0, RIGHT = 1};

class Object {
public:
  const int DEF_R_A_SPEED = 0.1;
  typedef QPointF point;
  typedef std::vector<point> cloud;

  Object(qreal x, qreal y,
         qreal speedAngle,
         qreal speedVal)
    :_pos(point(x,y))
    ,_speedVal(speedVal)
    ,_speedAngle(speedAngle)
    ,_rotateDir(STAY)
    ,_rotateAngleSpeed(DEF_R_A_SPEED){
  }

 Object(qreal x, qreal y)
   :Object(x,y,0,0) {
  }

  Object()
    :Object(0,0,0,0) {
  }

  point getPos() const;

  qreal getSpeedVal() const;

  qreal getSpeedAngle() const;

  dirType getRotateDir() const;

  qreal getRotateAngleSpeed() const;

  cloud getPointCloud();


  void setPos(point pos);

  void setPos(qreal x, qreal y);

  void setSpeedVal(qreal val) {
    _speedVal = val;
  }

  void setSpeedAngle(qreal angle);

  void setRotateDir(dirType dir);

  void setRotateAngleSpeed(qreal speed);

  void setPointCloud(cloud points) {
    _pointCloud = points;
  }


  virtual void update();
protected:

  void updatePos();

  void updateRotate();

  qreal normAngle(qreal angle);



  cloud _pointCloud;

  point _pos;

  qreal _speedVal;
  qreal _speedAngle;

  dirType _rotateDir;
  qreal _rotateAngleSpeed;
};

#endif // OBJECT_H
