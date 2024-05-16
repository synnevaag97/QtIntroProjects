#include "tst_player.h"

//TestPlayer::TestPlayer(){}

void TestPlayer::init()
{
    player = new Player();
}

void TestPlayer::getPlayerName()
{
    QString name = player->getPlayerName();
    QCOMPARE(name, ""); // Defualt initation
}
void TestPlayer::getPlayerMark()
{
    PlayerMark mark = player->getPlayerMark();
    QCOMPARE(mark, PlayerMark::X); // Defualt initation
}
void TestPlayer::getPlayerMarkString()
{
    QString mark = player->getPlayerMarkString();
    QCOMPARE(mark, "X"); // Defualt initation
}
void TestPlayer::isActivePlayer()
{
    bool isActive = player->isActivePlayer();
    QCOMPARE(isActive, false); // Defualt initation
}

void TestPlayer::setPlayerName()
{
    player->setPlayerName("Trym");

    QString name = player->getPlayerName();
    QCOMPARE(name, "Trym"); // Defualt initation
}
void TestPlayer::setPlayerMark()
{
    player->setPlayerMark(PlayerMark::O);

    PlayerMark mark = player->getPlayerMark();
    QCOMPARE(mark, PlayerMark::O); // Defualt initation
}
void TestPlayer::setActivePlayer()
{
    player->setActivePlayer(true);

    bool isActive = player->isActivePlayer();
    QCOMPARE(isActive, true); // Defualt initation
}

//QTEST_MAIN(TestPlayer)

//#include "tst_player.moc"
