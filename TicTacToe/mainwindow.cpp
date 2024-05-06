#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{

    w = new TicTacToe;
    v = new menu;
    QObject::connect(v, &menu::startButtonPressed, this, &MainWindow::showTicTacToe);
    QObject::connect(w, &TicTacToe::gameCompleted, this, &MainWindow::showMenu);
    QObject::connect(v, &menu::quitButtonPressed, this, &MainWindow::quitApplication);

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
