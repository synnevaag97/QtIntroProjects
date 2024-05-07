#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    setGeometry(0, 0, 350, 350);
    QWidget *centralWidget = new QWidget;
    setCentralWidget(centralWidget);

    // Main layout of front page.
    layout = new QVBoxLayout(centralWidget);
    centralWidget->setLayout(layout);

    // Initiate application modules.
    w = new TicTacToeBoard;
    v = new GameMenu;
    g = new GameLogic;
    p = new MultiPlayerRegistration;

    // Callbacks for menu buttons.
    QObject::connect(v,
                     &GameMenu::multiplayerSeleced,
                     this,
                     &MainWindow::showMultiPlayerRegistration);
    QObject::connect(v, &GameMenu::quitButtonPressed, this, &MainWindow::quitApplication);
    QObject::connect(p, &MultiPlayerRegistration::startGame, this, &MainWindow::showTicTacToe);

    // Callbacks for ingame communication between board and game logic.
    QObject::connect(g, &GameLogic::updateTextLabel, w, &TicTacToeBoard::updateTextLabel);
    QObject::connect(g, &GameLogic::updateBoxText, w, &TicTacToeBoard::updateBoxText);
    QObject::connect(g, &GameLogic::gameCompleted, w, &TicTacToeBoard::resetBoard);
    QObject::connect(w, &TicTacToeBoard::buttonPressed, g, &GameLogic::buttonPressed);

    // Callback to go back to menu when game is finished.
    QObject::connect(g, &GameLogic::gameCompleted, this, &MainWindow::showMenu);

    // Callback for sending player names.
    QObject::connect(p, &MultiPlayerRegistration::setPlayerNames, g, &GameLogic::setPlayerNames);

    layout->addWidget(w);
    layout->addWidget(v);
    layout->addWidget(p);
    p->hide();
    w->hide();
}

void MainWindow::showMultiPlayerRegistration()
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
