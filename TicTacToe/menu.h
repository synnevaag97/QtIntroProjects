#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>

#include "box.h"

class menu : public QWidget
{
    Q_OBJECT
public:
    explicit menu(QWidget *parent = nullptr);


    QPushButton *start_button; // Start button in start menu.
    //QPushButton *two_player_button;
    //QPushButton *settings_button;
    QPushButton *quit_button;

    QBoxLayout *menuLayout;

    void startButtonClicked();
    void quitButtonClicked();

signals:
    void startButtonPressed();
    void quitButtonPressed();
};

#endif // MENU_H
