#ifndef SCOREBOARDWIDGET_H
#define SCOREBOARDWIDGET_H

#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QStandardItemModel>
#include <QTableView>
#include <QVBoxLayout>
#include <QWidget>

#include "../Functionality/playerdatafilemanager.h"

class ScoreboardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScoreboardWidget(QWidget *parent = nullptr);

    QVBoxLayout *mainLayout;
    QTableView *resultView;

    QPushButton *clearScoreboard;
    QPushButton *returnToMenuButton;

    QStandardItemModel *model;

    PlayerDataFileManager *r;

    void updateModel();

signals:
    void returnToMenu();

private slots:
    void returnToMenuClicked();
    void clearScoreboardButtonClicked();
};

#endif // SCOREBOARDWIDGET_H
