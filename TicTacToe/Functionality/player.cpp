#include "player.h"

Player::Player()
{
    mark = PlayerMark::X;
}

void Player::setPlayerName(const QString name)
{
    this->name = name;
}
void Player::setPlayerMark(const PlayerMark mark)
{
    this->mark = mark;
}
void Player::setActivePlayer(const bool isActive)
{
    activePlayer = isActive;
}

QString Player::getPlayerName() const
{
    return name;
}
PlayerMark Player::getPlayerMark() const
{
    return mark;
}
QString Player::getPlayerMarkString() const
{
    switch (mark) {
    case X:
        return "X";
    case O:
        return "O";
    default:
        return ""; // Handle other cases if necessary
    }
}
bool Player::isActivePlayer() const
{
    return activePlayer;
}
