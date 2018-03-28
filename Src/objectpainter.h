#ifndef OBJECTPAINTER_H
#define OBJECTPAINTER_H


#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QPainter>
#include <objectbuilder.h>
#include <game_manager.h>
#include <controller.h>
#include <state.h>
class ObjectPainter : public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    explicit ObjectPainter(QObject *parent = 0);
    ObjectPainter (State *state);
    ~ObjectPainter();
    void keyPressEvent(QKeyEvent *event);

    void drawShip(std::shared_ptr<Ship> ship, QPainter *painter);
    void drawObject(std::shared_ptr<Object> object,QPainter *painter);
    void drawBullets(std::shared_ptr<State> state, QPainter *painter);
    void drawBullet(std::shared_ptr<Object> object, QPainter *painter);
    void drawAsteroid(std::shared_ptr<Object> asteroid, QPainter *painter);
    void drawAsteroids(std::shared_ptr<State> state, QPainter *painter);

signals:

public slots:
    void slotGameTimer();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);



private:
    std::shared_ptr<State> _state;


};

#endif // OBJECTPAINTER_H
