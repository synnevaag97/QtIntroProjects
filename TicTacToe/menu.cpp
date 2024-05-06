#include "menu.h"

menu::menu(QWidget *parent)
    : QWidget{parent}
{

    menuLayout = new QGridLayout;

    start_button = new QPushButton("Start Game");
    //two_player_button = new QPushButton("Two Player");
    //settings_button = new QPushButton("Settings");
    quit_button = new QPushButton("Quit");

    menuLayout->addWidget(start_button, 0,0);
    //menuLayout->addWidget(two_player_button, 1,0);
    //menuLayout->addWidget(settings_button, 2,0);
    menuLayout->addWidget(quit_button, 3,0);
    setLayout(menuLayout);

    connect(start_button, &Box::clicked, this, &menu::startButtonClicked);
    connect(quit_button, &Box::clicked, this, &menu::quitButtonClicked);

}


void menu::startButtonClicked(){
    // Code for handling start button click...

    emit startButtonPressed(); // Emit the signal when the start button is clicked
}

void menu::quitButtonClicked(){
    // Code for handling quit button click...

    emit quitButtonPressed(); // Emit the signal when the quit button is clicked
}
