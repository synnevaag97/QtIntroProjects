#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QVector>
#include <QLabel>
#include <QString>
//#include <QPushButton>
#include <QMessageBox>
#include <QObject>

#include <QtLogging>

#include "../Bots/easycomputer.h"
#include "../Bots/invincicomputer.h"
#include "../Bots/onelevelcomputer.h"
#include "../Bots/twolayercomputer.h"
#include "../Gui/box.h"
#include "gamestate.h"
#include "playerdatafilemanager.h"

enum GameMode { Singleplayer = 0, Multiplayer = 1 };

class GameLogic : public QObject
{
    Q_OBJECT

private:
    ComputerBase *computer;
    GameState state;
    GameMode gameMode;
    EasyComputer *easyComputer;
    OneLevelComputer *oneLevelComputer;
    TwoLayerComputer *twoLayerComputer;
    PlayerDataFileManager *r;
    InvinciComputer *invinciComputer;

    void updatePlayerTurn(); // These two should be 1?

public:
    GameLogic();
    void nextTurn();
    void resetGame();
    bool isLegalMove(Box *box);
    void setComputer(QString computerName);
    QVector<int> getLegalMoves();

signals:
    void updateTextLabel(const QString s);
    void updateBoxText(const QString s);
    void gameCompleted();
    void computerMove(int);

public slots:
    void buttonPressed(Box *box);
    void setPlayerNames(QString p1, QString p2);
    void setGameMode(GameMode mode);
};

#endif // GAMELOGIC_H
