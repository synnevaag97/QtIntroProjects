#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QVector>

#include "../Gui/box.h"
#include "player.h"

/*
 * State of the game.
 * */
class GameState
{
private:
    QVector<QVector<int>> boardState;
    QVector<Player> players;

public:
    GameState();
    GameState(const GameState &other);

    // Manipulation of members.
    void setBoxState(const int &row, const int &col);
    void setPlayerNames(const QString &p1, const QString &p2);
    void switchActivePlayer();
    void resetGameState();

    // Get data.
    QVector<int> getUnmarkedBoxes() const;
    QVector<QVector<int>> getBoardState() const;
    QVector<Player> getPlayers() const;
    Player getPlayer(const int player) const;
    Player getActivePlayer() const;
    Player getInActivePlayer() const;

    // Game specific logic.
    bool checkWinner();
    bool checkTie();
    bool isBoxMarked(Box *box);
};

#endif // GAMESTATE_H
