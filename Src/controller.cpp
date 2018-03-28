#include "controller.h"
#include <QKeyEvent>
#include <QDebug>
Controller::Controller(State* state)
    :_manager(state) {
}

void Controller::update() {
    qDebug()<<"UPDATE";
    _manager.update();
}

void Controller::keyPressEvent(QKeyEvent *event) {
    qDebug()<<"Controller KEY_PRESSED";
    switch(event->key()) {
    default:

        break;
    }
}

void Controller::keyReleaseEvent(QKeyEvent *event) {
    qDebug()<<"Controller KEY_RELEASED";
    switch(event->key()) {
    default:

        break;
    }
}

