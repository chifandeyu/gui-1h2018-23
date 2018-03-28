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
#include <game_manager.h>
#include <controller.h>
#include <objectpainter.h>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
   // Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
     void keyPressEvent(QKeyEvent *event);
     void keyReleaseEvent(QKeyEvent *event);
    ~Widget();


private:
    Ui::Widget      *ui;
    QGraphicsScene  *scene;
    TestModel       *model;
    std::shared_ptr<QTimer>          timer;
    std::shared_ptr<State>          _state;
    std::shared_ptr<Controller> _controller;
    std::shared_ptr<ObjectPainter> _objectPainter;

};

#endif // WIDGET_H
