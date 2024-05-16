#ifndef ONELEVELCOMPUTER_H
#define ONELEVELCOMPUTER_H

#include <QVector>

#include "../Functionality/gamestate.h"
#include "computerbase.h"

class OneLevelComputer : public ComputerBase
{
public:
    OneLevelComputer();
    int makeMove(GameState *state) override;
};

#endif // ONELEVELCOMPUTER_H
