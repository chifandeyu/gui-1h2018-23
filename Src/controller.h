#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game_manager.h"
#include "state.h"

class Controller :public QObject {
   // Q_OBJECT
private:

    GameManager _manager;

public:

    Controller(State* state);
public slots:
    void update();

};

#endif // CONTROLLER_H
