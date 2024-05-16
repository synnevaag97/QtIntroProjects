#include "easycomputer.h"

EasyComputer::EasyComputer() {}

int EasyComputer::makeMove(GameState *state)
{
    QVector<int> legalMoves = state->getUnmarkedBoxes();
    // Ensure there are legal moves available
    if (legalMoves.isEmpty()) {
        qWarning("No legal moves available.");
        return -1; // Or any other appropriate error code
    }

    // Calculate a move to do. Have to now what availible/legal. moves there is.
    int randomInt = QRandomGenerator::global()->bounded(legalMoves.size());
    return legalMoves[randomInt];
}
