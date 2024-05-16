#include "scoreboardwidget.h"

ScoreboardWidget::ScoreboardWidget(QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QVBoxLayout;
    setLayout(mainLayout);
    //QGridLayout *layout = new QGridLayout;
    //mainLayout->addLayout(layout);

    resultView = new QTableView();
    mainLayout->addWidget(resultView);

    // Clear scoreboard button
    clearScoreboard = new QPushButton();
    clearScoreboard->setText("Clear Scoreboard");
    clearScoreboard->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    mainLayout->addWidget(clearScoreboard);

    connect(clearScoreboard,
            &QPushButton::clicked,
            this,
            &ScoreboardWidget::clearScoreboardButtonClicked);

    // Back to menu button
    returnToMenuButton = new QPushButton();
    returnToMenuButton->setText("Back");
    returnToMenuButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    mainLayout->addWidget(returnToMenuButton);

    connect(returnToMenuButton, &QPushButton::clicked, this, &ScoreboardWidget::returnToMenuClicked);

    // Set up the model and configure the view...
    r = new PlayerDataFileManager;

    model = new QStandardItemModel;
    //model->setColumnCount(5);

    resultView->setModel(model);

    // Hide the vertical header and stretch the last section of the horizontal header
    resultView->verticalHeader()->hide();
    resultView->horizontalHeader()->setStretchLastSection(true);
}

void ScoreboardWidget::updateModel()
{
    model->clear();
    model->setHorizontalHeaderLabels({"Name", "Played", "Won", "Lost", "Draw"});

    QVector<QPair<QString, QVector<int>>> data = r->loadPlayerDataFromFile();

    for (const auto &pair : data) {
        QList<QStandardItem *> items;
        items.append(new QStandardItem(pair.first));

        for (int stat : pair.second) {
            items.append(new QStandardItem(QString::number(stat)));
        }

        model->appendRow(items);
    }
}

void ScoreboardWidget::returnToMenuClicked()
{
    emit returnToMenu();
}

void ScoreboardWidget::clearScoreboardButtonClicked()
{
    r->clearFile();
    updateModel();
}
