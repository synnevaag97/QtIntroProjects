#ifndef TICTACTOEBOARD_H
#define TICTACTOEBOARD_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QtWidgets>
#include <QLabel>
#include <QString>

#include <QtLogging>

#include "box.h"
#include "gamemenu.h"

/*
 * The TicTacToe Board.
 *
*/
class TicTacToeBoard : public  QWidget
{
    Q_OBJECT

public:
    TicTacToeBoard(QWidget *parent = nullptr);

    /*
    int whos_turn = 1; // 1 for player 1, 2 for player 2.
    int marked_tiles = 0;
    */

    QLabel *current_player_label;


    Box *button11;
    Box *button12;
    Box *button13;

    Box *button21;
    Box *button22;
    Box *button23;

    Box *button31;
    Box *button32;
    Box *button33;


    QGridLayout *tictacLayout;

    Box *lastButtonClicked;

    void handleButton();

    /*
    bool checkWinner(Box *buttonClicked);
    bool checkRow1(int player_mark);
    bool checkRow2(int player_mark);
    bool checkRow3(int player_mark);
    bool checkCol1(int player_mark);
    bool checkCol2(int player_mark);
    bool checkCol3(int player_mark);
    bool checkDiag1(int player_mark);
    bool checkDiag2(int player_mark);

    void restart();
    */

signals:
    void buttonPressed(Box *box);


public slots:
    void updateTextLabel(const QString s);
    void updateBoxText(const QString s);
    void gameCompleted();

};
#endif // TICTACTOEBOARD_H
