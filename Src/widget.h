#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>
#include <ship.h>
#include <state.h>
#include <testmodel.h>
#include <QPaintEvent>
#include <QPainter>
#include <objectbuilder.h>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    //Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void paintEvent( QPaintEvent *event );
    void drawShip(std::shared_ptr<Ship> ship, QPainter *painter);
    void drawObject(std::shared_ptr<Object> object,QPainter *painter);
    void drawBullets(std::shared_ptr<State> state, QPainter *painter);
    void drawBullet(std::shared_ptr<Object> object, QPainter *painter);
    void drawAsteroid(std::shared_ptr<Object> asteroid, QPainter *painter);
    void drawAsteroids(std::shared_ptr<State> state, QPainter *painter);
private:
    Ui::Widget      *ui;
    QGraphicsScene  *scene;
    TestModel       *model;
    QTimer          *timer;

};

#endif // WIDGET_H
