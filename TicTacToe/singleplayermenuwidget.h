#ifndef SINGLEPLAYERMENUWIDGET_H
#define SINGLEPLAYERMENUWIDGET_H

#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QWidget>

#include "playernamefilemanager.h"

class SinglePlayerMenuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SinglePlayerMenuWidget(QWidget *parent = nullptr);

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
    void startSinglePlayerGame();
    void returnToMenu();
    void setPlayerNames(QString p1, QString p2);
};

#endif // SINGLEPLAYERMENUWIDGET_H
