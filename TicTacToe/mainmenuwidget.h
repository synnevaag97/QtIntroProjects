#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

#include "box.h"

class MainMenuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenuWidget(QWidget *parent = nullptr);

    QPushButton *singleplayerButton; // Start button in start menu.
    QPushButton *multiplayerButton;
    QPushButton *scoreboardButton;
    QPushButton *quitButton;

    QBoxLayout *menuLayout;

    void singlePlayerButtonClicked();
    void multiPlayerButtonClicked();
    void scoreboardButtonClicked();
    void quitButtonClicked();

signals:
    void singlePlayerSeleced();
    void multiPlayerSeleced();
    void scoreBoardPressed();
    void quitButtonPressed();
};

#endif // MAINMENUWIDGET_H
