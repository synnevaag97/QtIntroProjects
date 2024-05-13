#ifndef INVINCICOMPUTER_H
#define INVINCICOMPUTER_H

#include <algorithm>

#include "computerbase.h"

class InvinciComputer : public ComputerBase
{
public:
    InvinciComputer();
    int makeMove(GameState *state) override;
    int minimax(GameState *state, int depth, bool isComputer);

private:
    int min_won = -10;
    int max_won = 10;
    int draw = 0;
};

#endif // INVINCICOMPUTER_H
