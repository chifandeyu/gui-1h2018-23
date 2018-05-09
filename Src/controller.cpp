#include "controller.h"
#include <QKeyEvent>
#include <QDebug>
Controller::Controller(State* state)
    :_manager(state) {
}

void Controller::update() {
    ///qDebug()<<"UPDATE";
    _manager.update();
}

void Controller::startGame() {
  _manager.initGame();
}

void Controller::keyPressEvent(QKeyEvent *event) {
    qDebug()<<"Controller KEY_PRESSED";
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
    qDebug()<<"Controller KEY_RELEASED";
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

