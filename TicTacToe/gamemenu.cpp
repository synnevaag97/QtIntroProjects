#include "gamemenu.h"

GameMenu::GameMenu(QWidget *parent)
    : QWidget{parent}
{

    menuLayout = new QBoxLayout(QBoxLayout::Direction::TopToBottom);

    singleplayerButton = new QPushButton("Singleplayer Game");
    multiplayerButton = new QPushButton("Multiplayer Game");
    //settings_button = new QPushButton("Settings");
    quitButton = new QPushButton("Quit");

    menuLayout->addWidget(singleplayerButton);
    menuLayout->addWidget(multiplayerButton);
    //menuLayout->addWidget(settings_button, 2,0);
    menuLayout->addWidget(quitButton);
    setLayout(menuLayout);

    connect(multiplayerButton, &Box::clicked, this, &GameMenu::multiplayerButtonClicked);
    connect(quitButton, &Box::clicked, this, &GameMenu::quitButtonClicked);

}


void GameMenu::multiplayerButtonClicked(){
    // Code for handling start button click...

    emit multiplayerButtonPressed(); // Emit the signal when the start button is clicked
}

void GameMenu::quitButtonClicked(){
    // Code for handling quit button click...

    emit quitButtonPressed(); // Emit the signal when the quit button is clicked
}
