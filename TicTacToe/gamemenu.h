#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>

#include "box.h"

class GameMenu : public QWidget
{
    Q_OBJECT
public:
    explicit GameMenu(QWidget *parent = nullptr);


    QPushButton *singleplayerButton; // Start button in start menu.
    QPushButton *multiplayerButton;
    //QPushButton *settings_button;
    QPushButton *quitButton;

    QBoxLayout *menuLayout;

    void multiplayerButtonClicked();
    void quitButtonClicked();

signals:
    void multiplayerButtonPressed();
    void quitButtonPressed();
};

#endif // GAMEMENU_H
