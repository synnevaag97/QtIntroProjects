#include "mainmenuwidget.h"

MainMenuWidget::MainMenuWidget(QWidget *parent)
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

    scoreboardButton = new QPushButton("Scoreboard");
    scoreboardButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    quitButton = new QPushButton("Quit");
    quitButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    menuLayout->addWidget(singleplayerButton);
    menuLayout->addWidget(multiplayerButton);
    menuLayout->addWidget(scoreboardButton);
    menuLayout->addWidget(quitButton);
    setLayout(menuLayout);

    connect(singleplayerButton, &Box::clicked, this, &MainMenuWidget::singlePlayerButtonClicked);
    connect(multiplayerButton, &Box::clicked, this, &MainMenuWidget::multiPlayerButtonClicked);
    connect(scoreboardButton, &Box::clicked, this, &MainMenuWidget::scoreboardButtonClicked);
    connect(quitButton, &Box::clicked, this, &MainMenuWidget::quitButtonClicked);
}

void MainMenuWidget::singlePlayerButtonClicked()
{
    // Code for handling start button click...

    emit singlePlayerSeleced(); // Emit the signal when the start button is clicked
}

void MainMenuWidget::multiPlayerButtonClicked()
{
    emit multiPlayerSeleced();
}

void MainMenuWidget::scoreboardButtonClicked()
{
    emit scoreBoardPressed();
}
void MainMenuWidget::quitButtonClicked()
{
    emit quitButtonPressed();
}
