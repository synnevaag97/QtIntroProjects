#ifndef COMPUTERBASE_H
#define COMPUTERBASE_H

#include <QRandomGenerator>

#include "../Functionality/gamestate.h"

class ComputerBase
{
public:
    ComputerBase();

    virtual int makeMove(GameState *state)
        = 0; // Pure virtual function. This makes the class a abstract function.
};

#endif // COMPUTERBASE_H
