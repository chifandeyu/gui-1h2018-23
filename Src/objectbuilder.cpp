#include "objectbuilder.h"
#define _USE_MATH_DEFINES

#include "object.h"
#include "ship.h"
#include <cmath>

ObjectBuilder::ObjectBuilder() {
}

std::shared_ptr<Object> ObjectBuilder::makeShip(qreal x, qreal y) {
  return std::shared_ptr<Object>(new Ship(x,y)); //!
}

std::shared_ptr<Object> ObjectBuilder::makeBullet(qreal x, qreal y) {
  Object* s = new Object(x, y);
  s->setPointCloud(Object::cloud({
        Object::point(0, 0.125),
        Object::point(0.125, 0),
        Object::point(0, -0.125),
        Object::point(-0.125, 0)}));
  return std::shared_ptr<Object>(s);
}

Object::cloud ObjectBuilder::generateAsteroidPoints(size_t size) {
  const int N = 12;
  const qreal angle = 2 * M_PI / N;
  const qreal rad = sqrt(size * size * (1 - cos(angle))/2);
  Object::cloud points;
  qreal x, y;
  qreal rand_angle;
  qreal rand_rad;
  for (int i = 0; i < N; i++) {
    rand_angle = 2*M_PI/(rand() % 100);
    rand_rad = ((qreal)rand() / RAND_MAX)*rad;
    x = size * cos(angle*i) + rand_rad * cos(rand_angle) - size/2;
    y = size * sin(angle*i) + rand_rad * sin(rand_angle) - size/2;
    points.push_back(Object::point(x, y));
  }
  return points;
}

std::shared_ptr<Object> ObjectBuilder::makeAsteroid(qreal x, qreal y, size_t size) {
  Object* s = new Object(x, y);
  s->setPointCloud(generateAsteroidPoints(size));
  return std::shared_ptr<Object>(s);
}
