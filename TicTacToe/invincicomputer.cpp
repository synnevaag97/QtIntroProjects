#include "invincicomputer.h"

InvinciComputer::InvinciComputer() {}

int InvinciComputer::makeMove(GameState *state)
{
    // Ensure there are legal moves available
    QVector<int> legalMoves = state->getLegalMoves();
    if (legalMoves.isEmpty()) {
        qWarning("No legal moves available.");
        return -1; // Or any other appropriate error code
    }

    int bestMove = -1;
    int bestVal = 1000;

    for (int move : legalMoves) {
        // Copy over for simulation
        GameState *newState = new GameState(*state);

        // Simulate a move.
        int row = move / 3; // Calculate row from index
        int col = move % 3;
        newState->updateGameState(row, col);

        int moveVal = minimax(newState, 0, false);

        if (moveVal < bestVal) {
            //qInfo("Current move val: %d, is larger then new best val: %d", bestVal, moveVal);
            bestVal = moveVal;
            bestMove = move;
            //qInfo("New Best move found is: %d. With score; %d", bestMove, bestVal);
        }
    }

    //qInfo("Best move is: %d. With score; %d", bestMove, bestVal);
    return bestMove;
}

int InvinciComputer::minimax(GameState *state, int depth, bool isComputer)
{
    QVector<int> legalMoves = state->getLegalMoves();

    if (state->checkWinner() && (state->getCurrentPlayer() == 2)) {
        //qInfo("Computer won this sim");
        return min_won + depth; // Adding depth to prioritize fastest win.
    }

    if (state->checkWinner() && (state->getCurrentPlayer() == 1)) {
        //qInfo("Player won this sim, returning %d", max_won);
        return max_won - depth;
    }

    if (legalMoves.isEmpty()) {
        //qInfo("Ended in a draw.");
        return draw;
    }

    if (!isComputer) {
        int best = -1000;

        for (int move : legalMoves) {
            // Copy over for simulation
            GameState *newState = new GameState(*state);

            // Simulate a move
            int row = move / 3; // Calculate row from index
            int col = move % 3;
            newState->setCurrentPlayer(1);
            newState->updateGameState(row, col);

            int score = minimax(newState, depth + 1, !isComputer);

            if (score > best) {
                best = score;
            }
        }
        return best;
    } else {
        int best = 1000;

        for (int move : legalMoves) {
            // Copy over for simulation
            GameState *newState = new GameState(*state);

            // Simulate a move
            int row = move / 3; // Calculate row from index
            int col = move % 3;
            newState->setCurrentPlayer(2);
            newState->updateGameState(row, col);

            int score = minimax(newState, depth + 1, !isComputer);
            if (score < best) {
                best = score;
            }
        }
        return best;
    }
    qInfo("Returned zero should not happen.");
    return 0;
}
