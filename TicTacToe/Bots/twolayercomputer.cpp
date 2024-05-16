#include "twolayercomputer.h"

TwoLayerComputer::TwoLayerComputer() {}

int TwoLayerComputer::makeMove(GameState *state)
{
    //QVector<QVector<int>> gameState = state->getState();

    // Ensure there are legal moves available
    QVector<int> legalMoves = state->getUnmarkedBoxes();
    if (legalMoves.isEmpty()) {
        qWarning("No legal moves available.");
        return -1; // Or any other appropriate error code
    }

    // Loop through potential legalMoves and see if any of them result in the bot winning or the opponent winning.
    int winningMoveBot = -1;
    int winningMoveOpponent = -1;
    for (int move : legalMoves) {
        // Copy over for simulation
        GameState *newState = new GameState(*state);

        // Simulate making a move
        int row = move / 3; // Calculate row from index
        int col = move % 3;
        newState->setBoxState(row, col);

        // Check if this move was a winning move for the bot
        if (newState->checkWinner()) {
            winningMoveBot = move;
        }

        // Check if this move was a winning move for the opponent
        newState->switchActivePlayer();
        newState->setBoxState(row, col);
        if (newState->checkWinner()) {
            winningMoveOpponent = move;
        }
    }

    if (winningMoveBot != -1) {
        return winningMoveBot;
    } else if (winningMoveOpponent != -1) {
        return winningMoveOpponent;
    }

    // Calculate a move to do. Have to now what availible/legal. moves there is.
    int randomInt = QRandomGenerator::global()->bounded(legalMoves.size());
    return legalMoves[randomInt];
}
