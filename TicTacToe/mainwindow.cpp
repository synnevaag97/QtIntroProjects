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
    pm = new MultiPlayerRegistration;
    ps = new SinglePlayerRegistration;

    // Callbacks for menu buttons.
    QObject::connect(v,
                     &GameMenu::multiPlayerSeleced,
                     this,
                     &MainWindow::showMultiPlayerRegistration);
    QObject::connect(v,
                     &GameMenu::singlePlayerSeleced,
                     this,
                     &MainWindow::showSinglePlayerRegistration);
    QObject::connect(v, &GameMenu::quitButtonPressed, this, &MainWindow::quitApplication);
    QObject::connect(ps,
                     &SinglePlayerRegistration::startSinglePlayerGame,
                     this,
                     &MainWindow::showTicTacToeSingle);
    QObject::connect(pm,
                     &MultiPlayerRegistration::startMultiPlayerGame,
                     this,
                     &MainWindow::showTicTacToeMulti);

    QObject::connect(ps, &SinglePlayerRegistration::returnToMenu, this, &MainWindow::showMenu);
    QObject::connect(pm, &MultiPlayerRegistration::returnToMenu, this, &MainWindow::showMenu);

    // Callbacks for in-game communication between board and game logic.
    QObject::connect(g, &GameLogic::updateTextLabel, w, &TicTacToeBoard::updateTextLabel);
    QObject::connect(g, &GameLogic::updateBoxText, w, &TicTacToeBoard::updateBoxText);
    QObject::connect(g, &GameLogic::gameCompleted, w, &TicTacToeBoard::resetBoard);
    QObject::connect(w, &TicTacToeBoard::buttonPressed, g, &GameLogic::buttonPressed);

    // Callback to go back to menu when game is finished.
    QObject::connect(g, &GameLogic::gameCompleted, this, &MainWindow::showMenu);

    // Callback for sending player name to gameLogic for registration page.
    QObject::connect(pm, &MultiPlayerRegistration::setPlayerNames, g, &GameLogic::setPlayerNames);
    QObject::connect(ps, &SinglePlayerRegistration::setPlayerNames, g, &GameLogic::setPlayerNames);

    // Callback for setting game mode; multi or single.
    QObject::connect(this, &MainWindow::setGameMode, g, &GameLogic::setGameMode);
    QObject::connect(this, &MainWindow::setGameMode, g, &GameLogic::setGameMode);

    // Computer move callback
    QObject::connect(g, &GameLogic::computerMove, w, &TicTacToeBoard::computerMove);

    layout->addWidget(w);
    layout->addWidget(v);
    layout->addWidget(pm);
    layout->addWidget(ps);
    ps->hide();
    pm->hide();
    w->hide();
}

void MainWindow::showSinglePlayerRegistration()
{
    emit setGameMode(Single);
    v->hide();
    ps->show();
}

void MainWindow::showMultiPlayerRegistration()
{
    emit setGameMode(Multi);
    v->hide();
    pm->show();
}

void MainWindow::showTicTacToeMulti()
{
    pm->hide();
    w->show();
}

void MainWindow::showTicTacToeSingle()
{
    ps->hide();
    w->show();
}

void MainWindow::showMenu()
{
    pm->hide();
    ps->hide();
    w->hide();
    v->show();
}

void MainWindow::quitApplication()
{
    close();
}
