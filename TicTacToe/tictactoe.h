#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QtWidgets>

#include <QtLogging>

#include "box.h"


class TicTacToe : public  QWidget
{
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr);

    int whos_turn; // 0 for player 1, 1 for player 2.
    Box *button11;// = new QPushButton("Button 11");
    Box *button12;// = new QPushButton("Button 12");
    Box *button13;// = new QPushButton("Button 13");

    Box *button21;// = new QPushButton("Button 21");
    Box *button22;// = new QPushButton("Button 22");
    Box *button23;// = new QPushButton("Button 23");

    Box *button31;// = new QPushButton("Button 31");
    Box *button32;// = new QPushButton("Button 32");
    Box *button33;// = new QPushButton("Button 33");

    void handleButton();


    bool checkWinner(Box *buttonClicked);
    bool checkRow1(int player_mark);


    bool checkRow2(int player_mark);
    bool checkRow3(int player_mark);
    bool checkCol1(int player_mark);
    bool checkCol2(int player_mark);
    bool checkCol3(int player_mark);
    bool checkDiag1(int player_mark);
    bool checkDiag2(int player_mark);

};
#endif // TICTACTOE_H
