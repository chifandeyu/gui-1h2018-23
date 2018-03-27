#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>
#include <ship.h>
#include <testmodel.h>
#include <QPaintEvent>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    //Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


    void drawShip(Ship *ship);
    void drawObject(Object *object);
    void paintEvent( QPaintEvent *event );
private:
    Ui::Widget      *ui;
    QGraphicsScene  *scene;
    TestModel       *model;
    QTimer          *timer;
};

#endif // WIDGET_H
