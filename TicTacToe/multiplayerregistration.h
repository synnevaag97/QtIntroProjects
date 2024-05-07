#ifndef MULTIPLAYERREGISTRATION_H
#define MULTIPLAYERREGISTRATION_H

#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QWidget>

/*
 * Class for 1 or 2 players to register their names. 
 * When sent to player registration we have input if it is single or multi. 
 * Depending on each of these we provide different menus and text over the menus. 
 * Also GameLogic must get info if it is single or multi?
 * Question is if this info should come when the object are initiated or when we press a button?
 * */
class MultiPlayerRegistration : public QWidget
{
    Q_OBJECT
public:
    explicit MultiPlayerRegistration(QWidget *parent = nullptr);

    QLabel *titleLabel;
    QLabel *player1Label;
    QLabel *player2Label;

    QLineEdit *player1;
    QLineEdit *player2;

    QPushButton *startGameButton;
    QPushButton *dropDownButton1;
    QPushButton *dropDownButton2;

    QMenu *dropDownMenu1;
    QMenu *dropDownMenu2;

private:
    void sendPlayerNames();

private slots:
    void startGameButtonClicked();
    void showDropDownMenu1();
    void showDropDownMenu2();

signals:
    void startGame();
    void setPlayerNames(QString p1, QString p2);
};

#endif // MULTIPLAYERREGISTRATION_H
