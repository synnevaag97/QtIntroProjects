#ifndef TST_PLAYER_H
#define TST_PLAYER_H

#include <QtTest/QtTest>

#include "../Functionality/player.h"

class TestPlayer : public QObject
{
    Q_OBJECT

private slots:
    void init();

    void getPlayerName();
    void getPlayerMark();
    void getPlayerMarkString();
    void isActivePlayer();

    void setPlayerName();
    void setPlayerMark();
    void setActivePlayer();

private:
    Player *player;
};

#endif // TST_PLAYER_H

/*

    void setPlayerName(const QString name);
    void setPlayerMark(const PlayerMark mark);
    void setActivePlayer(const bool isActive);

    QString getPlayerName() const;
    PlayerMark getPlayerMark() const;
    QString getPlayerMarkString() const;
    bool isActivePlayer() const;
 * */
