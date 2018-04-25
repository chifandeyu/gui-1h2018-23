#include "bullet.h"

Bullet::Bullet(qreal x, qreal y)
  :Object(x, y)
  ,_lifeTime(120) {
}

void Bullet::update() {
  Object::update();
  decLifeTime();
}
