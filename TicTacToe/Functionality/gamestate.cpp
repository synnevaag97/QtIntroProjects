#include "gamestate.h"

GameState::GameState()
{
    boardState.resize(3);
    for (int i = 0; i < 3; ++i) {
        boardState[i].resize(3);
    }
    players.resize(2);
    players[0].setActivePlayer(true);
    players[1].setActivePlayer(false);

    players[0].setPlayerMark(X);
    players[1].setPlayerMark(O);

    // Initialize all elements to -1
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            boardState[i][j] = -1;
        }
    }
}

/*
 * Copy consructor
 * */
GameState::GameState(const GameState &other)
{
    // Copy the member variables
    this->boardState = other.getBoardState();
    this->players = other.getPlayers();
}

void GameState::setBoxState(const int &row, const int &col)
{
    // Check if row and col are within the valid range
    Q_ASSERT_X(row >= 0 && row < 3 && col >= 0 && col < 3,
               "GameState::setBoxState",
               "Invalid row or column value");

    Player currentPlayer = getActivePlayer();
    boardState[row][col] = currentPlayer.getPlayerMark();
}

void GameState::setPlayerNames(const QString &p1, const QString &p2)
{
    players[0].setPlayerName(p1);
    players[1].setPlayerName(p2);
}

void GameState::switchActivePlayer()
{
    if (players[0].isActivePlayer()) {
        players[0].setActivePlayer(false);
        players[1].setActivePlayer(true);
    } else {
        players[0].setActivePlayer(true);
        players[1].setActivePlayer(false);
    }
}

void GameState::resetGameState()
{
    players[0].setActivePlayer(true);
    players[1].setActivePlayer(false);

    players[0].setPlayerName("");
    players[1].setPlayerName("");

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            boardState[i][j] = -1;
        }
    }
}

QVector<int> GameState::getUnmarkedBoxes() const
{
    QVector<int> unmarkedBoxes;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (boardState[i][j] == -1) {
                int index = i * 3 + j;
                unmarkedBoxes.push_back(index);
            }
        }
    }
    return unmarkedBoxes;
}

QVector<QVector<int>> GameState::getBoardState() const
{
    return boardState;
}
QVector<Player> GameState::getPlayers() const
{
    return players;
}
Player GameState::getPlayer(int player) const
{
    return players[player - 1];
}

Player GameState::getActivePlayer() const
{
    if (players[0].isActivePlayer()) {
        return players[0];
    } else {
        return players[1];
    }
}

Player GameState::getInActivePlayer() const
{
    if (!players[0].isActivePlayer()) {
        return players[0];
    } else {
        return players[1];
    }
}

bool GameState::checkWinner()
{
    Player currentPlayer = this->getActivePlayer();
    PlayerMark currentPlayerMark = currentPlayer.getPlayerMark();

    // Check rows
    for (int i = 0; i < 3; ++i) {
        if ((boardState[i][0] == currentPlayerMark) && (boardState[i][1] == currentPlayerMark)
            && (boardState[i][2] == currentPlayerMark))
            return true;
    }

    // Check Cols
    for (int j = 0; j < 3; ++j) {
        if ((boardState[0][j] == currentPlayerMark) && (boardState[1][j] == currentPlayerMark)
            && (boardState[2][j] == currentPlayerMark))
            return true;
    }

    // Check Diagonals
    if ((boardState[0][0] == currentPlayerMark) && (boardState[1][1] == currentPlayerMark)
        && (boardState[2][2] == currentPlayerMark))
        return true;
    if ((boardState[2][0] == currentPlayerMark) && (boardState[1][1] == currentPlayerMark)
        && (boardState[0][2] == currentPlayerMark))
        return true;

    return false;
}

bool GameState::checkTie()
{
    int numMarkedBoxes = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (boardState[i][j] != -1) {
                numMarkedBoxes++;
            }
        }
    }

    if (numMarkedBoxes >= 9) {
        return true;
    }

    return false;
}

bool GameState::isBoxMarked(Box *box)
{
    if (boardState[std::get<0>(box->location)][std::get<1>(box->location)] != -1) {
        return true;
    }
    return false;
}
