#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

enum PlayerMark { X = 1, O = 2 };

class Player
{
private:
    QString name;
    PlayerMark mark;
    bool activePlayer;

public:
    Player();
    void setPlayerName(const QString name);
    void setPlayerMark(const PlayerMark mark);
    void setActivePlayer(const bool isActive);

    QString getPlayerName() const;
    PlayerMark getPlayerMark() const;
    QString getPlayerMarkString() const;
    bool isActivePlayer() const;
};

#endif // PLAYER_H
