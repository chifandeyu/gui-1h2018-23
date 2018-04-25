#ifndef OBJECTBUILDER_H
#define OBJECTBUILDER_H

#include "object.h"
#include <memory>


class ObjectBuilder {
 public:
  ObjectBuilder();

  std::shared_ptr<Object> makeShip(qreal x, qreal y);

  std::shared_ptr<Object> makeBullet(qreal x, qreal y);

  std::shared_ptr<Object> makeAsteroid(qreal x, qreal y, size_t size);

  Object::cloud generateAsteroidPoints(size_t size);
};

#endif // OBJECTBUILDER_H
