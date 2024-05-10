#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "gamelogic.h"
#include "gamemenu.h"
#include "multiplayerregistration.h"
#include "singleplayerregistration.h"
#include "tictactoeboard.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    TicTacToeBoard *w;
    GameMenu *v;
    GameLogic *g;
    MultiPlayerRegistration *pm;
    SinglePlayerRegistration *ps;
    QVBoxLayout *layout;
    //QWidget *centralWidget;

signals:
    void setGameMode(GameMode mode);

public slots:
    void showMultiPlayerRegistration();
    void showSinglePlayerRegistration();
    void showTicTacToeSingle();
    void showTicTacToeMulti();
    void showMenu();
    void quitApplication();
};

#endif // MAINWINDOW_H
