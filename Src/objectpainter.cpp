#include "objectpainter.h"
#include <QDebug>

#define _USE_MATH_DEFINES

#include <cmath>

ObjectPainter::ObjectPainter(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    //angle = 0;
    // setRotation(angle);
}

ObjectPainter::ObjectPainter(State *state) :
    _state(state)
{

}

ObjectPainter::~ObjectPainter()
{

}

void ObjectPainter::keyPressEvent(QKeyEvent *event)
{

}
/*
QRectF ObjectPainter::boundingRect() const
{
    return QRectF(-25,-40,50,80);
}
*/
void ObjectPainter::drawLifeBar(std::shared_ptr<State> state, QPainter *painter)
{
   //painter->drawText(50,50,(QString)(state.get()->life));

    painter->drawText(45,45,"Life");
    painter->drawText(50,55,QString::number(state->life));



}

void ObjectPainter::drawScoreBar(std::shared_ptr<State> state,QPainter *painter)
{
    //painter->drawText(350,50,(QString) (state.get()->score));
    painter->drawText(350,40,"Score");
    painter->drawText(350,50,QString::number(state->score));

}
void ObjectPainter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  QRect game_space (0,0,_state->width,_state->height);
  painter->drawRect(game_space);
  painter->fillRect(game_space,Qt::black);

  painter->setPen(Qt::white);
  drawLifeBar(_state,painter);
  drawScoreBar(_state,painter);
  drawShip(_state->ship, _state, painter);
  drawAsteroids(_state->objects, _state, painter);
  drawBullets(_state->bullets, _state, painter);

  Q_UNUSED(option);
  Q_UNUSED(widget);
}

void ObjectPainter::slotGameTimer()
{
   std::shared_ptr< QPainter> painter(new QPainter);

   qDebug()<<"paint";
   qDebug()<<"slotGameTimer";
}

QRectF ObjectPainter::boundingRect() const
{

}


inline void ObjectPainter::drawShip(std::shared_ptr<Ship> ship, std::shared_ptr<State> state, QPainter *painter) {
  if (!(state->flags.at("shipIsDeth"))) {
      painter->translate(ship->getPos().x(), ship->getPos().y());
      painter->rotate(ship->getAccAngle()/2/M_PI * 360);
      painter->translate(-ship->getPos().x(), -ship->getPos().y());
      drawObject(std::dynamic_pointer_cast<Object>(ship),  state, painter);
      painter->resetTransform();
  }
}

inline void ObjectPainter::drawBullet(State::bullet_ptr object, std::shared_ptr<State> state, QPainter *painter) {
    drawObject(object, state, painter);
}

inline void ObjectPainter::drawAsteroids(State::object_vec objects, std::shared_ptr<State> state, QPainter *painter)
{
    for (auto asteriod : objects)
        drawAsteroid(asteriod, state, painter);

}

inline void ObjectPainter::drawAsteroid(std::shared_ptr<Object> asteroid, std::shared_ptr<State> state, QPainter *painter)
{
    drawObject(asteroid, state, painter);
}


void ObjectPainter::drawObject(std::shared_ptr<Object> object, std::shared_ptr<State> state, QPainter *painter)
{

    Object::cloud points=object->getPointCloud();
    auto scale = state->scale;
    for (size_t i=0; i<points.size()-1;i++)
        painter->drawLine(object->getPos()+points[i]*scale,object->getPos()+points[i+1]*scale);
    painter->drawLine(object->getPos()+points.front()*scale,object->getPos()+points.back()*scale);


}

void ObjectPainter::drawBullets(State::bullet_vec bullets, std::shared_ptr<State> state, QPainter *painter)
{
    for (auto bullet : bullets)
        drawBullet(bullet, state, painter);

}

