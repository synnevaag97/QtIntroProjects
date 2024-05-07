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

enum PlayerMark {
    X = 1,
    O = 2
};

class GameLogic : public QObject
{
    Q_OBJECT
public:
    GameLogic();
    void init();

    QVector<QVector<int>> gameState;
    int whos_turn; // 1 for player 1, 2 for player 2.
    int marked_tiles;
    QLabel *current_player_label;

    bool checkWinner(Box *box);
    bool checkRow1(int player_mark);
    bool checkRow2(int player_mark);
    bool checkRow3(int player_mark);
    bool checkCol1(int player_mark);
    bool checkCol2(int player_mark);
    bool checkCol3(int player_mark);
    bool checkDiag1(int player_mark);
    bool checkDiag2(int player_mark);

    bool isLegalMove(Box *box);
    bool checkTie();
    void nextTurn();
    void updateGameState(Box *box);
    void restart();

signals:
    void updateTextLabel(const QString s);
    void updateBoxText(const QString s);
    void gameCompleted();

public slots:
    void buttonPressed(Box *box);
};

#endif // GAMELOGIC_H
