#include "onelevelcomputer.h"

OneLevelComputer::OneLevelComputer() {}

int OneLevelComputer::makeMove(GameState *state)
{
    //QVector<QVector<int>> boardState = state->getBoardState();

    // Ensure there are legal moves available
    QVector<int> legalMoves = state->getUnmarkedBoxes();
    if (legalMoves.isEmpty()) {
        qWarning("No legal moves available.");
        return -1; // Or any other appropriate error code
    }

    // Loop through potential legalMoves and see if any of them result in the bot winning.
    int winningMove = -1;
    for (int move : legalMoves) {
        // Copy over for simulation
        GameState *newState = new GameState(*state);

        // SImulate making a move
        int row = move / 3; // Calculate row from index
        int col = move % 3;
        newState->setBoxState(row, col);

        // Check if this move was a winning move
        if (newState->checkWinner()) {
            winningMove = move;
        }
    }

    if (winningMove != -1) {
        return winningMove;
    }

    // Calculate a move to do. Have to now what availible/legal. moves there is.
    int randomInt = QRandomGenerator::global()->bounded(legalMoves.size());
    return legalMoves[randomInt];
}
