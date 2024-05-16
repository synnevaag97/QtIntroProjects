#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../Functionality/gamelogic.h"
#include "mainmenuwidget.h"
#include "multiplayermenuwidget.h"
#include "scoreboardwidget.h"
#include "singleplayermenuwidget.h"
#include "tictactoeboardwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    TicTacToeBoardWidget *w;
    MainMenuWidget *v;
    GameLogic *g;
    MultiPlayerMenuWidget *pm;
    SinglePlayerMenuWidget *ps;
    QVBoxLayout *layout;
    //QWidget *centralWidget;

    ScoreboardWidget *scoreboard;

signals:
    void setGameMode(GameMode mode);

public slots:
    void showMultiPlayerRegistration();
    void showSinglePlayerRegistration();
    void showScoreboard();
    void showTicTacToeSingle();
    void showTicTacToeMulti();
    void showMenu();
    void quitApplication();
};

#endif // MAINWINDOW_H
