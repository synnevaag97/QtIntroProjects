#include "tictactoeboard.h"

/*
 * Constructor for TicTacTie class
 * It takes a QWidget pointer object called parent as parameter. WHich is the base class for all widgets.
*/
TicTacToeBoard::TicTacToeBoard(QWidget *parent)
    : QWidget(parent)
{
    // Create main layout and grid.
    QVBoxLayout *mainLayout = new QVBoxLayout();
    tictacLayout = new QGridLayout;

    // Create label for stating player to play.
    current_player_label = new QLabel();
    current_player_label->setAlignment(Qt::AlignCenter);
    current_player_label->setText("");

    // Add widget and layout to main layout.
    mainLayout->addWidget(current_player_label);
    mainLayout->addLayout(tictacLayout);
    setLayout(mainLayout);

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
    tictacLayout->addWidget(button11, 0, 0);
    tictacLayout->addWidget(button12, 0, 1);
    tictacLayout->addWidget(button13, 0, 2);

    tictacLayout->addWidget(button21, 1, 0);
    tictacLayout->addWidget(button22, 1, 1);
    tictacLayout->addWidget(button23, 1, 2);

    tictacLayout->addWidget(button31, 2, 0);
    tictacLayout->addWidget(button32, 2, 1);
    tictacLayout->addWidget(button33, 2, 2);

    // Connect buttons to handle when clicked.
    connect(button11, &Box::clicked, this, &TicTacToeBoard::boxPressedHandle);
    connect(button12, &Box::clicked, this, &TicTacToeBoard::boxPressedHandle);
    connect(button13, &Box::clicked, this, &TicTacToeBoard::boxPressedHandle);

    connect(button21, &Box::clicked, this, &TicTacToeBoard::boxPressedHandle);
    connect(button22, &Box::clicked, this, &TicTacToeBoard::boxPressedHandle);
    connect(button23, &Box::clicked, this, &TicTacToeBoard::boxPressedHandle);

    connect(button31, &Box::clicked, this, &TicTacToeBoard::boxPressedHandle);
    connect(button32, &Box::clicked, this, &TicTacToeBoard::boxPressedHandle);
    connect(button33, &Box::clicked, this, &TicTacToeBoard::boxPressedHandle);
}

void TicTacToeBoard::boxPressedHandle()
{
    lastButtonClicked = qobject_cast<Box *>(sender());
    if (!lastButtonClicked)
        return;

    // Send the pressed button to gameLogic to update stuff. Since it points to the button the gameLogic should be able to update the text of the box.
    emit buttonPressed(lastButtonClicked);
}

void TicTacToeBoard::updateTextLabel(const QString s)
{
    // Change so we get the name and update the text sprcifically here.
    current_player_label->setText(s);
}

void TicTacToeBoard::updateBoxText(const QString s)
{
    // Update so we get the player sign and have the string here instead?
    lastButtonClicked->setText(s);
}

void TicTacToeBoard::resetBoard()
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
