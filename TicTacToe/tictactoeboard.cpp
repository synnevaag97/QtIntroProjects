#include "tictactoeboard.h"

/*
 * Constructor for TicTacTie class
 * It takes a QWidget pointer object called parent as parameter. WHich is the base class for all widgets.
*/
TicTacToeBoard::TicTacToeBoard(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    tictacLayout = new QGridLayout;

    current_player_label = new QLabel();
    current_player_label->setAlignment(Qt::AlignCenter);
    current_player_label->setText("");
    mainLayout->addWidget(current_player_label);
    mainLayout->addLayout(tictacLayout);

    // Create three x three buttons
    button11 = new Box(0, 0);
    button12 = new Box(0, 1);
    button13 = new Box(0, 2);

    button21 = new Box(1, 0);
    button22 = new Box(1, 1);
    button23 = new Box(1, 2);

    button31 = new Box(2, 0);
    button32 = new Box(2, 1);
    button33 = new Box(2, 2);

    // Create a 3x3 grid for the game
    tictacLayout->addWidget(button11, 1, 0); // Add button1 at row 0, column 0
    tictacLayout->addWidget(button12, 1, 1); // Add button2 at row 0, column 1
    tictacLayout->addWidget(button13,
                            1,
                            2); // Add button3 spanning from row 1 to row 2 and column 0 to column 1

    tictacLayout->addWidget(button21, 2, 0);
    tictacLayout->addWidget(button22, 2, 1);
    tictacLayout->addWidget(button23, 2, 2);

    tictacLayout->addWidget(button31, 3, 0);
    tictacLayout->addWidget(button32, 3, 1);
    tictacLayout->addWidget(button33, 3, 2);

    setLayout(mainLayout);

    // Connect buttons to handle on clicked.
    connect(button11, &Box::clicked, this, &TicTacToeBoard::handleButton);
    connect(button12, &Box::clicked, this, &TicTacToeBoard::handleButton);
    connect(button13, &Box::clicked, this, &TicTacToeBoard::handleButton);

    connect(button21, &Box::clicked, this, &TicTacToeBoard::handleButton);
    connect(button22, &Box::clicked, this, &TicTacToeBoard::handleButton);
    connect(button23, &Box::clicked, this, &TicTacToeBoard::handleButton);

    connect(button31, &Box::clicked, this, &TicTacToeBoard::handleButton);
    connect(button32, &Box::clicked, this, &TicTacToeBoard::handleButton);
    connect(button33, &Box::clicked, this, &TicTacToeBoard::handleButton);
}

void TicTacToeBoard::handleButton()
{
    lastButtonClicked = qobject_cast<Box *>(sender());
    if (!lastButtonClicked)
        return;

    emit buttonPressed(
        lastButtonClicked); // Send the pressed button to gameLogic to update stuff. Since it points to the button the gameLogic should be able to update the text of the box.
}

void TicTacToeBoard::updateTextLabel(const QString s)
{
    current_player_label->setText(s);
}

void TicTacToeBoard::updateBoxText(const QString s)
{
    lastButtonClicked->setText(s);
}

void TicTacToeBoard::gameCompleted()
{
    button11->setText("");
    button12->setText("");
    button13->setText("");
    button21->setText("");
    button22->setText("");
    button23->setText("");
    button31->setText("");
    button32->setText("");
    button33->setText("");

    QString s = QString("Player 1(X) starts the game.");
    current_player_label->setText(s);
}
