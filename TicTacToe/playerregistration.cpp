#include "playerregistration.h"

PlayerRegistration::PlayerRegistration(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *mainLayout = new QVBoxLayout();

    // Title of page.
    titleLabel = new QLabel();
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setText("Who is playing?");
    mainLayout->addWidget(titleLabel);

    // Create grid
    QGridLayout *gridLayout = new QGridLayout();
    mainLayout->addLayout(gridLayout);

    // Show Player 1 and player 2 text labels.
    player1Label = new QLabel();
    player1Label->setAlignment(Qt::AlignCenter);
    player1Label->setText("Player 1: ");
    gridLayout->addWidget(player1Label, 0, 0);

    player2Label = new QLabel();
    player2Label->setAlignment(Qt::AlignCenter);
    player2Label->setText("Player 2: ");
    gridLayout->addWidget(player2Label, 0, 1);

    // Show box to write their names in.
    player1 = new QLineEdit();
    player1->setAlignment(Qt::AlignCenter);
    gridLayout->addWidget(player1, 1, 0);

    player2 = new QLineEdit();
    player2->setAlignment(Qt::AlignCenter);
    gridLayout->addWidget(player2, 1, 1);

    // Continue to game button
    continueToGameButton = new QPushButton();
    continueToGameButton->setText("Continue");
    continueToGameButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    mainLayout->addWidget(continueToGameButton);

    connect(continueToGameButton,
            &QPushButton::clicked,
            this,
            &PlayerRegistration::continueToGameButtonClicked);

    setLayout(mainLayout);
}

void PlayerRegistration::continueToGameButtonClicked()
{
    // Code for handling button click...
    sendPlayerNames();
    emit continueToGame(); // Emit the signal when the button is clicked

    // Should i send the input names through the emit?? We want the name in the gameLogic. And let's say that the gameLogic is the one that communicate with the scoreboard.
}

void PlayerRegistration::sendPlayerNames()
{
    QString player1_name = player1->text();
    player1->clear();
    QString player2_name = player2->text();
    player2->clear();
    emit setPlayerNames(player1_name, player2_name);
}
