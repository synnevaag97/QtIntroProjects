#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

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

    void singlePlayerButtonClicked();
    void multiPlayerButtonClicked();
    void quitButtonClicked();

signals:
    void singlePlayerSeleced();
    void multiPlayerSeleced();
    void quitButtonPressed();
};

#endif // GAMEMENU_H
