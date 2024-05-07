#include "gamemenu.h"

GameMenu::GameMenu(QWidget *parent)
    : QWidget{parent}
{
    menuLayout = new QBoxLayout(QBoxLayout::Direction::TopToBottom);
    menuLayout->setAlignment(Qt::AlignCenter);
    menuLayout->setSpacing(20);

    // Create title of game.
    QLabel *titleLabel = new QLabel("Welcome to My TicTacToe Game", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    menuLayout->addWidget(titleLabel);

    singleplayerButton = new QPushButton("Singleplayer Game");
    singleplayerButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    multiplayerButton = new QPushButton("Multiplayer Game");
    multiplayerButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    //settings_button = new QPushButton("Settings");
    quitButton = new QPushButton("Quit");
    quitButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    menuLayout->addWidget(singleplayerButton);
    menuLayout->addWidget(multiplayerButton);
    //menuLayout->addWidget(settings_button, 2,0);
    menuLayout->addWidget(quitButton);
    setLayout(menuLayout);

    connect(multiplayerButton, &Box::clicked, this, &GameMenu::multiplayerButtonClicked);
    connect(quitButton, &Box::clicked, this, &GameMenu::quitButtonClicked);
}

void GameMenu::multiplayerButtonClicked()
{
    // Code for handling start button click...

    emit multiplayerButtonPressed(); // Emit the signal when the start button is clicked
}

void GameMenu::quitButtonClicked()
{
    // Code for handling quit button click...

    emit quitButtonPressed(); // Emit the signal when the quit button is clicked
}
