#include "gamestate.h"

GameState::GameState()
{
    gameState.resize(3);
    for (int i = 0; i < 3; ++i) {
        gameState[i].resize(3);
    }

    currentPlayer = 1;
    playerNames.resize(2);

    // Initialize all elements to -1
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            gameState[i][j] = -1;
        }
    }
}

void GameState::updateGameState(Box *box)
{
    gameState[std::get<0>(box->location)][std::get<1>(box->location)] = currentPlayer;
}

bool GameState::checkTie()
{
    int numMarkedBoxes = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameState[i][j] != -1) {
                numMarkedBoxes++;
            }
        }
    }

    if (numMarkedBoxes >= 9) {
        return true;
    }

    return false;
}

QVector<int> GameState::getLegalMoves()
{
    QVector<int> legalMoves;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gameState[i][j] == -1) {
                int index = i * 3 + j;
                legalMoves.push_back(index);
            }
        }
    }
    return legalMoves;
}

bool GameState::isBoxMarked(Box *box)
{
    /*qInfo("Box that is being checked: %d , %d, %d",
          std::get<0>(box->location),
          std::get<1>(box->location),
          gameState[std::get<0>(box->location)][std::get<1>(box->location)]);*/
    if (gameState[std::get<0>(box->location)][std::get<1>(box->location)] != -1) {
        return true;
    }
    return false;
}

bool GameState::checkWinner()
{
    /* Check if any rows, cols or diag are equal to one players mark. 
    */

    // Check rows
    for (int i = 0; i < 3; ++i) {
        if ((gameState[i][0] == currentPlayer) && (gameState[i][1] == currentPlayer)
            && (gameState[i][2] == currentPlayer))
            return true;
    }

    // Check Cols
    for (int j = 0; j < 3; ++j) {
        if ((gameState[0][j] == currentPlayer) && (gameState[1][j] == currentPlayer)
            && (gameState[2][j] == currentPlayer))
            return true;
    }

    // Check Diagonals
    if ((gameState[0][0] == currentPlayer) && (gameState[1][1] == currentPlayer)
        && (gameState[2][2] == currentPlayer))
        return true;
    if ((gameState[2][0] == currentPlayer) && (gameState[1][1] == currentPlayer)
        && (gameState[0][2] == currentPlayer))
        return true;

    return false;
}

void GameState::reset()
{
    currentPlayer = 1;
    playerNames[0] = "";
    playerNames[1] = "";

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            gameState[i][j] = -1;
        }
    }
}

void GameState::setPlayerNames(QString p1, QString p2)
{
    playerNames[0] = p1;
    playerNames[1] = p2;
}

void GameState::updatePlayerTurn()
{
    if (currentPlayer == 1) {
        currentPlayer = 2;
    } else if (currentPlayer == 2) {
        currentPlayer = 1;
    }
}

QString GameState::getPlayerName(int player)
{
    return playerNames[player - 1];
}
QString GameState::getPlayerMark(int player)
{
    return player == PlayerMark::X ? "X" : "O";
}

QString GameState::getCurrentPlayerName()
{
    return getPlayerName(currentPlayer);
}
QString GameState::getCurrentPlayerMark()
{
    return getPlayerMark(currentPlayer);
}