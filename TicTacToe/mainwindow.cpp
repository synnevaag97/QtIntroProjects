#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{

    w = new TicTacToeBoard;
    v = new GameMenu;
    g = new GameLogic;

    // Callbacks for menu buttons.
    QObject::connect(v, &GameMenu::multiplayerButtonPressed, this, &MainWindow::showTicTacToe);
    QObject::connect(v, &GameMenu::quitButtonPressed, this, &MainWindow::quitApplication);


    // Callbacks for ingame logics.
    QObject::connect(g, &GameLogic::updateTextLabel, w, &TicTacToeBoard::updateTextLabel);
    QObject::connect(g, &GameLogic::updateBoxText, w, &TicTacToeBoard::updateBoxText);
    QObject::connect(g, &GameLogic::gameCompleted, w, &TicTacToeBoard::gameCompleted);
    QObject::connect(w, &TicTacToeBoard::buttonPressed, g, &GameLogic::buttonPressed);
    QObject::connect(g, &GameLogic::gameCompleted, this, &MainWindow::showMenu);

    layout = new QVBoxLayout;
    layout->addWidget(w);
    layout->addWidget(v);
    w->hide();

    // Create a central widget for the main window and set the layout
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void MainWindow::showTicTacToe()
{
    v->hide();
    w->show();
}

void MainWindow::showMenu()
{
    w->hide();
    v->show();
}

void MainWindow::quitApplication(){
    close();
}
