#ifndef BULLETS_H
#define BULLETS_H

#include "object.h"

class Bullet : public Object {
 public:
  Bullet(qreal x, qreal y);
  void decLifeTime() {
    _lifeTime--;
  }
  virtual void update();
  int getLifeTime() const {
    return _lifeTime;
  }
 private:
  int _lifeTime;
};

#endif // BULLETS_H
