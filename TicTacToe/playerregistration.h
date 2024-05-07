#ifndef PLAYERREGISTRATION_H
#define PLAYERREGISTRATION_H

#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

/*
 * Class for 1 or 2 players to register their names. 
 * */
class PlayerRegistration : public QWidget
{
    Q_OBJECT
public:
    explicit PlayerRegistration(QWidget *parent = nullptr);

    QLabel *titleLabel;
    QLabel *player1Label;
    QLabel *player2Label;

    QLineEdit *player1;
    QLineEdit *player2;

    QPushButton *continueToGameButton;

    void continueToGameButtonClicked();
    void sendPlayerNames();

signals:
    void continueToGame();
    void setPlayerNames(QString p1, QString p2);
};

#endif // PLAYERREGISTRATION_H
