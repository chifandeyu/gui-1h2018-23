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
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QTextBlock>

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
    std::shared_ptr<QTimer>          timer;
    std::shared_ptr<State>          _state;
    std::shared_ptr<Controller> _controller;
    std::shared_ptr<ObjectPainter> _objectPainter;
    std::shared_ptr<QGridLayout> _grid ;
    std::shared_ptr<QGroupBox> _menu;
    std::shared_ptr<QGroupBox> _score;
   // std::shared_ptr<QGroupBox> _option;
    std::shared_ptr<QGroupBox> _gameOverScreen;

    bool pause;
    bool start;

    int n =1;
    size_t _w;
    size_t _h;


    QWidget *EmptyMenu();
    QGroupBox *createMenu();
    QGroupBox *createScoreMenu();
    QGroupBox *createOptionMenu();
    QGroupBox *createGameOverMenu();



private slots:

    void openGameOverScreen();
    void startGame();
    void openGameScore();
    void openOption();
    void quitGame();
    void backToMaintMenu();
    void backFromOptionToMaintMenu();
    void updateScore(QLabel *lab);
    void backToMaintMenuAfterGameOver();
    void changeSoundPresence(QPushButton *button);
    void resizeScreen(size_t w,size_t h);



signals:
    void firstWindow();
    void gameOver();
    void openScore();



};

#endif // WIDGET_H
