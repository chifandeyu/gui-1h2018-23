#include "controller.h"
#include <QKeyEvent>
#include <QDebug>
Controller::Controller(State* state, int width, int height)
    :_manager(state) {
    resize(width,height);
}

void Controller::update() {

    _manager.update();
}

void Controller::startGame() {
  _manager.initGame();
}

void Controller::keyPressEvent(QKeyEvent *event) {
    switch(event->key())
    {
    case Qt::Key_Up:
        _manager.turnOnAcc();
        break;
    case Qt::Key_Left:
        _manager.turnOnRotateLeft();
        break;
    case Qt::Key_Right:
        _manager.turnOnRotateRight();
        break;
    case Qt::Key_Space:
        _manager.strike();
        break;

    default:
        break;
    }
}

void Controller::keyReleaseEvent(QKeyEvent *event) {

    switch(event->key())
    {
    case Qt::Key_Up:
        _manager.turnOffAcc();
        break;
    case Qt::Key_Left:
        _manager.turnOffRotateLeft();
        break;
    case Qt::Key_Right:
        _manager.turnOffRotateRight();
        break;
    case Qt::Key_Space:

        break;
    default:
        break;
    }
}

void Controller::resize(int width, int height) {
    _manager.resize(width, height);
}

void Controller::writeScore(QString name)
{
    _manager.saveScore(name);
}

