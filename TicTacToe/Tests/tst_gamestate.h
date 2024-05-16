#ifndef TST_GAMESTATE_H
#define TST_GAMESTATE_H

#include <QtTest/QtTest>
#include "../Functionality/gamestate.h"
#include "tst_player.h"
class TestGameState : public QObject
{
    Q_OBJECT

private slots:
    void init();
    //void setBoxState();
    void setPlayerNames();
    void switchActivePlayer();
    void resetGameState();

    void getUnmarkedBoxes();
    void getBoardState();
    void getPlayers();
    void getPlayer();
    void getActivePlayer();
    void getInActivePlayer();

    //private slots:
    //void handleAssertion(const QString &message);

private:
    //bool assertionCaught;
    GameState *gameState;
};

/* All these functions need to be tested for GameState class. 


    // Game specific logic.The two below should be in gamelogic. Only thing is that it is easier for the computer to define if winner or tie or loss...
    bool checkWinner();
    bool checkTie();


    // THis should be in gameState. 
    bool isBoxMarked(Box *box);
 * 
 * */

#endif // TST_GAMESTATE_H
