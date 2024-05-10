#include "multiplayermenuwidget.h"

MultiPlayerMenuWidget::MultiPlayerMenuWidget(PlayerMenuBaseWidget *parent)
    : PlayerMenuBaseWidget{parent}
{
    setLayout(mainLayout);

    player1Label->setText("Player 1: ");
    player2Label->setText("Player 2: ");

    player1Input->setPlaceholderText("Enter your name");
    player2Input->setPlaceholderText("Enter your name");
}

void MultiPlayerMenuWidget::showDropDownMenu2()
{
    // Add some example names to the dropdown menu
    dropDownMenu2->clear();
    QVector<QString> names = r->loadNamesFromFile();
    for (const QString &name : names) {
        QAction *action2 = dropDownMenu2->addAction(name);
        connect(action2, &QAction::triggered, this, [this, name]() { player2Input->setText(name); });
    }

    // Show the dropdown menu below the dropdown button
    dropDownMenu2->exec(dropDownButton2->mapToGlobal(
        QPoint(-(dropDownButton1->width() * 5), dropDownButton2->height())));
}
