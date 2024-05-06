#include "tictactoe.h"

/*
 * Constructor for TicTacTie class
 * It takes a QWidget pointer object called parent as parameter. WHich is the base class for all widgets.
*/
TicTacToe::TicTacToe(QWidget *parent)
    : QWidget(parent)
{

    tictacLayout = new QGridLayout;

    // Create three x three buttons
    button11 = new Box();
    button12 = new Box();
    button13 = new Box();

    button21 = new Box();
    button22 = new Box();
    button23 = new Box();

    button31 = new Box();
    button32 = new Box();
    button33 = new Box();

    // Create a 3x3 grid for the game
    //QGridLayout *mainLayout = new QGridLayout;
    tictacLayout->addWidget(button11, 0, 0);  // Add button1 at row 0, column 0
    tictacLayout->addWidget(button12, 0, 1);  // Add button2 at row 0, column 1
    tictacLayout->addWidget(button13, 0, 2);  // Add button3 spanning from row 1 to row 2 and column 0 to column 1

    tictacLayout->addWidget(button21, 1, 0);
    tictacLayout->addWidget(button22, 1, 1);
    tictacLayout->addWidget(button23, 1, 2);

    tictacLayout->addWidget(button31, 2, 0);
    tictacLayout->addWidget(button32, 2, 1);
    tictacLayout->addWidget(button33, 2, 2);

    setLayout(tictacLayout);

    // Connect buttons to handle on clicked.
    connect(button11, &Box::clicked, this, &TicTacToe::handleButton);
    connect(button12, &Box::clicked, this, &TicTacToe::handleButton);
    connect(button13, &Box::clicked, this, &TicTacToe::handleButton);

    connect(button21, &Box::clicked, this, &TicTacToe::handleButton);
    connect(button22, &Box::clicked, this, &TicTacToe::handleButton);
    connect(button23, &Box::clicked, this, &TicTacToe::handleButton);

    connect(button31, &Box::clicked, this, &TicTacToe::handleButton);
    connect(button32, &Box::clicked, this, &TicTacToe::handleButton);
    connect(button33, &Box::clicked, this, &TicTacToe::handleButton);
}


void TicTacToe::handleButton(){
    Box *buttonClicked = qobject_cast<Box*>(sender());
    if (!buttonClicked)
        return;

    if(whos_turn == 0){
        buttonClicked->setText("X");
        whos_turn = 1;
        buttonClicked->player = 0;
    } else {
        buttonClicked->setText("O");
        whos_turn = 0;
        buttonClicked->player = 1;
    }

    if (checkWinner(buttonClicked)){
        // We have a winner. If not continues.
        qInfo("Winner winner chicken dinner! Player: %d Won", buttonClicked->player);
        QMessageBox::information(
            this,
            tr("Winner!"),
            tr("Winner winner chicken dinner! Player: %1 Won").arg(buttonClicked->player) );

        emit gameCompleted();
        restart();
    }
}


bool TicTacToe::checkWinner(Box *buttonClicked){
    // When on click check if we have a winner.
    bool finished = false;
    // Determine which button was clicked
    if (buttonClicked == button11) {
        // Check row1, col1 and diag1
        int player_mark =button11->player;
        if(checkRow1(player_mark))return true;
        if(checkCol1(player_mark))return true;
        if(checkDiag1(player_mark))return true;

    } else if (buttonClicked == button12) {
        // Check row1, col2
        int player_mark =button12->player;
        if(checkRow1(player_mark))return true;
        if(checkCol2(player_mark))return true;

    } else if (buttonClicked == button13) {
        // Check row1, col3 and diag2
        int player_mark =button13->player;
        if(checkRow1(player_mark))return true;
        if(checkCol3(player_mark))return true;
        if(checkDiag2(player_mark))return true;

    } else if (buttonClicked == button21) {
        // Check row2, col1
        int player_mark =button21->player;
        if(checkRow2(player_mark))return true;
        if(checkCol1(player_mark))return true;


    } else if (buttonClicked == button22) {
        // Check row2, col2 and diag1 and diag 2
        int player_mark =button22->player;
        if(checkRow2(player_mark))return true;
        if(checkCol2(player_mark))return true;
        if(checkDiag1(player_mark))return true;
        if(checkDiag2(player_mark))return true;

    } else if (buttonClicked == button23) {
        // Check row2, col3
        int player_mark =button23->player;
        if(checkRow2(player_mark))return true;
        if(checkCol3(player_mark))return true;

    } else if (buttonClicked == button31) {
        // Check row3, col1 and diag2
        int player_mark =button31->player;
        if(checkRow3(player_mark))return true;
        if(checkCol1(player_mark))return true;
        if(checkDiag2(player_mark))return true;

    } else if (buttonClicked == button32) {
        // Check row3, col2 and
        int player_mark =button32->player;
        if(checkRow3(player_mark))return true;
        if(checkCol2(player_mark))return true;

    } else if (buttonClicked == button33) {
        // Check row3, col3 and diag1
        int player_mark =button33->player;
        if(checkRow3(player_mark))return true;
        if(checkCol3(player_mark))return true;
        if(checkDiag1(player_mark))return true;
    }

    return finished;
}


bool TicTacToe::checkRow1(int player_mark){
    if (button11->player == player_mark && button12->player == player_mark && button13->player == player_mark) {
        //qInfo("%d", player_mark);
        //qInfo("%d", button11->player);
        //qInfo("%d", button12->player);
        //qInfo("%d", button13->player);
        return true;
    }

    return false;
}


bool TicTacToe::checkRow2(int player_mark){
    if (button21->player == player_mark && button22->player == player_mark && button23->player == player_mark) {
        return true;
    }

    return false;
}
bool TicTacToe::checkRow3(int player_mark){
    if (button31->player == player_mark && button32->player == player_mark && button33->player == player_mark) {
        return true;
    }

    return false;
}
bool TicTacToe::checkCol1(int player_mark){
    if (button11->player == player_mark && button21->player == player_mark && button31->player == player_mark) {
        return true;
    }

    return false;
}
bool TicTacToe::checkCol2(int player_mark){
    if (button12->player == player_mark && button22->player == player_mark && button32->player == player_mark) {
        return true;
    }

    return false;
}
bool TicTacToe::checkCol3(int player_mark){
    if (button13->player == player_mark && button23->player == player_mark && button33->player == player_mark) {
        return true;
    }

    return false;
}
bool TicTacToe::checkDiag1(int player_mark){
    if (button11->player == player_mark && button22->player == player_mark && button33->player == player_mark) {
        return true;
    }

    return false;
}
bool TicTacToe::checkDiag2(int player_mark){
    if (button13->player == player_mark && button22->player == player_mark && button31->player == player_mark) {
        return true;
    }

    return false;
}

void TicTacToe::restart(){
    button11->setText("");
    button11->player = -1;

    button12->setText("");
    button12->player = -1;

    button13->setText("");
    button13->player = -1;

    button21->setText("");
    button21->player = -1;

    button22->setText("");
    button22->player = -1;

    button23->setText("");
    button23->player = -1;

    button31->setText("");
    button31->player = -1;

    button32->setText("");
    button32->player = -1;

    button33->setText("");
    button33->player = -1;
}
