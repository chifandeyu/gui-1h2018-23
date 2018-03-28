#include "objectpainter.h"
#include <QDebug>
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
void ObjectPainter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void ObjectPainter::slotGameTimer()
{
   std::shared_ptr< QPainter> painter(new QPainter);
   // drawShip(_state->ship,painter);
  //  drawAsteroids(_state,painter);
  //  drawBullets(_state,painter);
    qDebug()<<"paint";
    qDebug()<<"slotGameTimer";
}

QRectF ObjectPainter::boundingRect() const
{

}


inline void ObjectPainter::drawShip(std::shared_ptr<Ship> ship,QPainter *painter) {

    drawObject(std::dynamic_pointer_cast<Object>(ship),painter);
}

inline void ObjectPainter::drawBullet(std::shared_ptr<Object> object, QPainter *painter) {
    drawObject(object,painter);
}

inline void ObjectPainter::drawAsteroids(std::shared_ptr<State> state, QPainter *painter)
{
    for (auto asteriod : state->objects)
        drawBullet(asteriod,painter);

}

inline void ObjectPainter::drawAsteroid(std::shared_ptr<Object> asteroid, QPainter *painter)
{
    drawObject(asteroid,painter);
}


void ObjectPainter::drawObject(std::shared_ptr<Object> object,QPainter *painter)
{
    Object::cloud points=object->getPointCloud();
    for (size_t i=1;i<points.size();i++)
        painter->drawLine(object->getPos()+points[i-1]*25,object->getPos()+points[i]*25);
    painter->drawLine(object->getPos()+points.front()*25,object->getPos()+points.back()*25);


}

void ObjectPainter::drawBullets(std::shared_ptr<State> state, QPainter *painter)
{
    for (auto bullet : state->bullets)
        drawBullet(bullet,painter);

}

