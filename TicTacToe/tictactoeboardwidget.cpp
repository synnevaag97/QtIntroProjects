#include "tictactoeboardwidget.h"

/*
 * Constructor for TicTacTie class
 * It takes a QWidget pointer object called parent as parameter. WHich is the base class for all widgets.
*/
TicTacToeBoardWidget::TicTacToeBoardWidget(QWidget *parent)
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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Box *button = new Box(i, j);
            boxes.push_back(button);
        }
    }

    // Create a 3x3 grid for the game

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int index = i * 3 + j;
            tictacLayout->addWidget(boxes[index], i, j);
        }
    }

    // Connect buttons to handle when clicked.

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int index = i * 3 + j;
            connect(boxes[index], &Box::clicked, this, &TicTacToeBoardWidget::boxPressedHandle);
        }
    }
}

void TicTacToeBoardWidget::boxPressedHandle(bool p)
{
    lastButtonClicked = qobject_cast<Box *>(sender());
    if (!lastButtonClicked)
        return;

    // Send the pressed button to gameLogic to update stuff. Since it points to the button the gameLogic should be able to update the text of the box.
    emit buttonPressed(lastButtonClicked);
}

void TicTacToeBoardWidget::updateTextLabel(const QString s)
{
    // Change so we get the name and update the text sprcifically here.
    current_player_label->setText(s);
}

void TicTacToeBoardWidget::updateBoxText(const QString s)
{
    // Update so we get the player sign and have the string here instead?
    lastButtonClicked->setText(s);
}

void TicTacToeBoardWidget::resetBoard()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int index = i * 3 + j;
            boxes[index]->setText("");
        }
    }
    QString s = QString("Player 1(X) starts the game.");
    current_player_label->setText(s);
}

void TicTacToeBoardWidget::computerMove(int move)
{
    //qDebug("Computer to move %s", boxes[move]->isEnabled() ? "true" : "false");
    boxes[move]->animateClick();
    lastButtonClicked = boxes[move];
    //emit buttonPressed(boxes[move]);

    /* When using click() i cannot get the button pressed with sender(). Therefore i need to provide additional info. 
     * */
}
