#ifndef EASYCOMPUTER_H
#define EASYCOMPUTER_H

#include <QVector>

#include "computerbase.h"

class EasyComputer : public ComputerBase
{
public:
    EasyComputer();
    int makeMove(GameState *state) override;
};

#endif // EASYCOMPUTER_H
