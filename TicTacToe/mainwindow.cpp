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
    w = new TicTacToeBoardWidget;
    v = new MainMenuWidget;
    g = new GameLogic;
    pm = new MultiPlayerMenuWidget;
    ps = new SinglePlayerMenuWidget;

    // Callbacks for menu buttons.
    QObject::connect(v,
                     &MainMenuWidget::multiPlayerSeleced,
                     this,
                     &MainWindow::showMultiPlayerRegistration);
    QObject::connect(v,
                     &MainMenuWidget::singlePlayerSeleced,
                     this,
                     &MainWindow::showSinglePlayerRegistration);
    QObject::connect(v, &MainMenuWidget::quitButtonPressed, this, &MainWindow::quitApplication);
    QObject::connect(ps,
                     &SinglePlayerMenuWidget::startSinglePlayerGame,
                     this,
                     &MainWindow::showTicTacToeSingle);
    QObject::connect(pm,
                     &MultiPlayerMenuWidget::startMultiPlayerGame,
                     this,
                     &MainWindow::showTicTacToeMulti);

    QObject::connect(ps, &SinglePlayerMenuWidget::returnToMenu, this, &MainWindow::showMenu);
    QObject::connect(pm, &MultiPlayerMenuWidget::returnToMenu, this, &MainWindow::showMenu);

    // Callbacks for in-game communication between board and game logic.
    QObject::connect(g, &GameLogic::updateTextLabel, w, &TicTacToeBoardWidget::updateTextLabel);
    QObject::connect(g, &GameLogic::updateBoxText, w, &TicTacToeBoardWidget::updateBoxText);
    QObject::connect(g, &GameLogic::gameCompleted, w, &TicTacToeBoardWidget::resetBoard);
    QObject::connect(w, &TicTacToeBoardWidget::buttonPressed, g, &GameLogic::buttonPressed);

    // Callback to go back to menu when game is finished.
    QObject::connect(g, &GameLogic::gameCompleted, this, &MainWindow::showMenu);

    // Callback for sending player name to gameLogic for registration page.
    QObject::connect(pm, &MultiPlayerMenuWidget::setPlayerNames, g, &GameLogic::setPlayerNames);
    QObject::connect(ps, &SinglePlayerMenuWidget::setPlayerNames, g, &GameLogic::setPlayerNames);

    // Callback for setting game mode; multi or single.
    QObject::connect(this, &MainWindow::setGameMode, g, &GameLogic::setGameMode);
    QObject::connect(this, &MainWindow::setGameMode, g, &GameLogic::setGameMode);

    // Computer move callback
    QObject::connect(g, &GameLogic::computerMove, w, &TicTacToeBoardWidget::computerMove);

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
