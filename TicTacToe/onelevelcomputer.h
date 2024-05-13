#ifndef ONELEVELCOMPUTER_H
#define ONELEVELCOMPUTER_H

#include <QVector>

#include "computerbase.h"
#include "gamestate.h"

class OneLevelComputer : public ComputerBase
{
public:
    OneLevelComputer();
    int makeMove(GameState *state) override;
};

#endif // ONELEVELCOMPUTER_H
