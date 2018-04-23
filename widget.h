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
#include <QGridLayout>
#include <QGroupBox>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
     void keyPressEvent(QKeyEvent *event);
     void keyReleaseEvent(QKeyEvent *event);
     void paintEvent(QPaintEvent *event);
     ~Widget();


     void newGame() {
       _controller->startGame();
     }

private:
    Ui::Widget      *ui;
    std::shared_ptr <QGraphicsScene>  scene;
    //QGraphicsScene  *scene;
   // TestModel       *model;
    std::shared_ptr<QTimer>          timer;
    std::shared_ptr<State>          _state;
    std::shared_ptr<Controller> _controller;
    std::shared_ptr<ObjectPainter> _objectPainter;
    std::shared_ptr<QGridLayout> _grid ;
    std::shared_ptr<QGroupBox> _menu;
    bool pause;

    QWidget *em1 =EmptyMenu();
    QWidget *em2 =EmptyMenu();

    QWidget *EmptyMenu();
    QGroupBox *createMenu();
public slots:
    void startGame();
    void openGameScore();
    void quitGame();


signals:
    void firstWindow();

};

#endif // WIDGET_H
