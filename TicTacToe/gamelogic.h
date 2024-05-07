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
#include "gamestate.h"

class GameLogic : public QObject
{
    Q_OBJECT
public:
    GameState state;

    GameLogic();
    void nextTurn();
    void restart();

signals:
    void updateTextLabel(const QString s);
    void updateBoxText(const QString s);
    void gameCompleted();

public slots:
    void buttonPressed(Box *box);
    void setPlayerNames(QString p1, QString p2);
};

#endif // GAMELOGIC_H
