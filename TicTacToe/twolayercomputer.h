#ifndef TWOLAYERCOMPUTER_H
#define TWOLAYERCOMPUTER_H

#include "computerbase.h"

class TwoLayerComputer : public ComputerBase
{
public:
    TwoLayerComputer();

    int makeMove(GameState *state) override;
};

#endif // TWOLAYERCOMPUTER_H
