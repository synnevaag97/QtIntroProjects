#include "singleplayermenuwidget.h"

SinglePlayerMenuWidget::SinglePlayerMenuWidget(PlayerMenuBaseWidget *parent)
    : PlayerMenuBaseWidget{parent}
{
    setLayout(mainLayout);

    player1Label->setText("Player 1: ");
    player2Label->setText("Computer: ");

    player1Input->setPlaceholderText("Enter your name");
    player2Input->setPlaceholderText("Choose computer");
    player2Input->setEnabled(false);

    QStringList computers = {"Easy Computer",
                             "Smart Computer",
                             "Smarter Computer",
                             "Invinci Computer"};
    for (const QString &name : computers) {
        QAction *action2 = dropDownMenu2->addAction(name);
        connect(action2, &QAction::triggered, this, [this, name]() { player2Input->setText(name); });
    }
}

void SinglePlayerMenuWidget::sendPlayerNames()
{
    QString player1_name = player1Input->text();
    player1Input->clear();
    QString player2_name = player2Input->text();
    player2Input->clear();

    QVector<QString> names = {player1_name};
    r->addNewPlayersToFile(names);

    emit setPlayerNames(player1_name, player2_name);
}
