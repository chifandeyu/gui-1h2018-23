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

    void drawShip(std::shared_ptr<Ship> ship, std::shared_ptr<State> state, QPainter *painter);
    void drawObject(std::shared_ptr<Object> object, std::shared_ptr<State> state, QPainter *painter);
    void drawBullets(State::object_vec objects, std::shared_ptr<State> state, QPainter *painter);
    void drawBullet(std::shared_ptr<Object> object, std::shared_ptr<State> state, QPainter *painter);
    void drawAsteroid(std::shared_ptr<Object> asteroid, std::shared_ptr<State> state, QPainter *painter);
    void drawAsteroids(State::object_vec objects, std::shared_ptr<State> state, QPainter *painter);

signals:

public slots:
    void slotGameTimer();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    QRectF boundingRect() const;



private:
    std::shared_ptr<State> _state;


};

#endif // OBJECTPAINTER_H
