#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tictactoe.h"
#include "menu.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    TicTacToe *w;
    menu *v;
    QVBoxLayout *layout;
    //QWidget *centralWidget;

signals:

public slots:
    void showTicTacToe();
    void showMenu();
    void quitApplication();

};

#endif // MAINWINDOW_H
