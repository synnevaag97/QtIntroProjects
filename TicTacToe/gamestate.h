#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QVector>

#include "box.h"

enum PlayerMark { X = 1, O = 2 };

/*
 * State of the game.
 * */
class GameState
{
private:
    QVector<QVector<int>> gameState;
    int currentPlayer; // 1 for player 1, 2 for player 2.
    QVector<QString> playerNames;

public:
    GameState();
    GameState(const GameState &other);

    bool checkWinner();
    bool checkTie();
    void updateGameState(int row, int col);
    void setPlayerNames(QString p1, QString p2);
    void reset();
    void updatePlayerTurn();
    bool isBoxMarked(Box *box);
    void setCurrentPlayer(int player);
    void clearState(int row, int col);

    QVector<int> getLegalMoves();
    int getMarkedBoxes();
    QString getPlayerName(int player);
    QString getPlayerMark(int player);
    QString getCurrentPlayerName();
    QString getCurrentPlayerMark();
    QString getOtherPlayerName();

    QVector<QVector<int>> getState() const;
    int getCurrentPlayer() const;
    QVector<QString> getPlayerNames() const;
};

#endif // GAMESTATE_H
