#ifndef OBJECT_H
#define OBJECT_H

#include<QPointF>
#include <utility>
#include <vector>

enum dirType { LEFT = -1, STAY = 0, RIGHT = 1};

class Object {
public:

  typedef QPointF point;
  typedef std::vector<point> cloud;

  Object(qreal x, qreal y,
         qreal speedAngle,
         qreal speedVal)
    :_pos(point(x,y))
    ,_speedVal(speedVal)
    ,_speedAngle(speedAngle) {
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

  cloud getPointCloud() {
    return _pointCloud;
  }

  qreal getSize() {
    return _size;
  }


  void setPos(point pos);

  void setPos(qreal x, qreal y) {
    _pos = point(x, y);
  }

  void setSpeedVal(qreal val) {
    _speedVal = val;
  }

  void setSpeedAngle(qreal angle);

  void setPointCloud(cloud points) {
    _pointCloud = points;
  }

  void setSize(qreal size) {
    _size = size;
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

  qreal _size;

};

#endif // OBJECT_H
