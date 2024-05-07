#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    setGeometry(0, 0, 350, 350);
    QWidget *centralWidget = new QWidget;
    setCentralWidget(centralWidget);

    // Main layout of front page.
    layout = new QVBoxLayout(centralWidget);

    w = new TicTacToeBoard;
    v = new GameMenu;
    g = new GameLogic;
    p = new PlayerRegistration;

    // Callbacks for menu buttons.
    QObject::connect(v,
                     &GameMenu::multiplayerButtonPressed,
                     this,
                     &MainWindow::showPlayerRegistration);
    QObject::connect(v, &GameMenu::quitButtonPressed, this, &MainWindow::quitApplication);
    QObject::connect(p, &PlayerRegistration::continueToGame, this, &MainWindow::showTicTacToe);

    // Callbacks for ingame logics.
    QObject::connect(g, &GameLogic::updateTextLabel, w, &TicTacToeBoard::updateTextLabel);
    QObject::connect(g, &GameLogic::updateBoxText, w, &TicTacToeBoard::updateBoxText);
    QObject::connect(g, &GameLogic::gameCompleted, w, &TicTacToeBoard::gameCompleted);
    QObject::connect(w, &TicTacToeBoard::buttonPressed, g, &GameLogic::buttonPressed);
    QObject::connect(g, &GameLogic::gameCompleted, this, &MainWindow::showMenu);

    // Callback for sending player names
    QObject::connect(p, &PlayerRegistration::setPlayerNames, g, &GameLogic::setPlayerNames);

    layout->addWidget(w);
    layout->addWidget(v);
    layout->addWidget(p);
    p->hide();
    w->hide();

    // Create a central widget for the main window and set the layout
    centralWidget->setLayout(layout);
}

void MainWindow::showPlayerRegistration()
{
    v->hide();
    p->show();
}

void MainWindow::showTicTacToe()
{
    p->hide();
    w->show();
}

void MainWindow::showMenu()
{
    w->hide();
    v->show();
}

void MainWindow::quitApplication()
{
    close();
}
