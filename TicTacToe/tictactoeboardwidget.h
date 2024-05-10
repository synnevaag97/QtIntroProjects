#ifndef TICTACTOEBOARDWIDGET_H
#define TICTACTOEBOARDWIDGET_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QtWidgets>
#include <QLabel>
#include <QString>

#include <QtLogging>

#include "box.h"
#include "mainmenuwidget.h"

/*
 * The TicTacToe Board.
 *
*/
class TicTacToeBoardWidget : public QWidget
{
    Q_OBJECT

public:
    TicTacToeBoardWidget(QWidget *parent = nullptr);

    QGridLayout *tictacLayout;
    QLabel *current_player_label;
    QVector<Box *> boxes;

    Box *lastButtonClicked;

    void boxPressedHandle(bool p);

signals:
    void buttonPressed(Box *box);


public slots:
    void updateTextLabel(const QString s);
    void updateBoxText(const QString s);
    void resetBoard();
    void computerMove(int move);
};
#endif // TICTACTOEBOARDWIDGET_H
