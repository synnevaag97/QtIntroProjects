#ifndef MULTIPLAYERMENUWIDGET_H
#define MULTIPLAYERMENUWIDGET_H

#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QWidget>

#include "playernamefilemanager.h"

/*
 * Class for 1 or 2 players to register their names. 
 * When sent to player registration we have input if it is single or multi. 
 * Depending on each of these we provide different menus and text over the menus. 
 * Also GameLogic must get info if it is single or multi?
 * Question is if this info should come when the object are initiated or when we press a button?
 * */
class MultiPlayerMenuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MultiPlayerMenuWidget(QWidget *parent = nullptr);

    QLabel *titleLabel;
    QLabel *player1Label;
    QLabel *player2Label;

    QLineEdit *player1;
    QLineEdit *player2;

    QPushButton *startGameButton;
    QPushButton *returnToMenuButton;
    QPushButton *dropDownButton1;
    QPushButton *dropDownButton2;

    QMenu *dropDownMenu1;
    QMenu *dropDownMenu2;

    PlayerNameFileManager *r;

private:
    void sendPlayerNames();

private slots:
    void startGameButtonClicked();
    void returnToMenuClicked();
    void showDropDownMenu1();
    void showDropDownMenu2();

signals:
    void startMultiPlayerGame();
    void returnToMenu();
    void setPlayerNames(QString p1, QString p2);
};

#endif // MULTIPLAYERMENUWIDGET_H
