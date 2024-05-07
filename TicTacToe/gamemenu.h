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

    void multiplayerButtonClicked();
    void quitButtonClicked();

signals:
    void multiplayerSeleced();
    void quitButtonPressed();
};

#endif // GAMEMENU_H
