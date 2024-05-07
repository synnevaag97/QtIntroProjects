#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "gamelogic.h"
#include "gamemenu.h"
#include "multiplayerregistration.h"
#include "tictactoeboard.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    TicTacToeBoard *w;
    GameMenu *v;
    GameLogic *g;
    MultiPlayerRegistration *p;
    QVBoxLayout *layout;
    //QWidget *centralWidget;

signals:

public slots:
    void showMultiPlayerRegistration();
    void showTicTacToe();
    void showMenu();
    void quitApplication();
};

#endif // MAINWINDOW_H
