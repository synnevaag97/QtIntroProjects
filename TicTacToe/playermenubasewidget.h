#ifndef PLAYERMENUBASEWIDGET_H
#define PLAYERMENUBASEWIDGET_H

#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QWidget>

#include "playerdatafilemanager.h"

class PlayerMenuBaseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlayerMenuBaseWidget(QWidget *parent = nullptr);

protected:
    QVBoxLayout *mainLayout;

    QLabel *titleLabel;
    QLabel *player1Label;
    QLabel *player2Label;

    QLineEdit *player1Input;
    QLineEdit *player2Input;

    QMenu *dropDownMenu1;
    QMenu *dropDownMenu2;
    QPushButton *dropDownButton1;
    QPushButton *dropDownButton2;

    QPushButton *startGameButton;
    QPushButton *returnToMenuButton;

    PlayerDataFileManager *r;

    virtual void sendPlayerNames();

signals:
    void startGame();
    void returnToMenu();
    void setPlayerNames(const QString &p1, const QString &p2);

private slots:
    void startGameButtonClicked();
    void returnToMenuClicked();
    void showDropDownMenu1();
    virtual void showDropDownMenu2();
};

#endif // PLAYERMENUBASEWIDGET_H
