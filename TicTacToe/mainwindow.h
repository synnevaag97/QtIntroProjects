#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tictactoeboard.h"
#include "gamemenu.h"
#include "gamelogic.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    TicTacToeBoard *w;
    GameMenu *v;
    GameLogic *g;
    QVBoxLayout *layout;
    //QWidget *centralWidget;

signals:

public slots:
    void showTicTacToe();
    void showMenu();
    void quitApplication();

};

#endif // MAINWINDOW_H
