#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QVector>
#include <QLabel>
#include <QString>
//#include <QPushButton>
#include <QMessageBox>
#include <QObject>

#include <QtLogging>

#include "box.h"
#include "easycomputer.h"
#include "gamestate.h"

enum GameMode { Single = 0, Multi = 1 };

class GameLogic : public QObject
{
    Q_OBJECT
public:
    GameState state;
    GameMode gameMode;
    EasyComputer computer;

    GameLogic();
    void nextTurn();
    void restart();
    bool isLegalMove(Box *box);

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
