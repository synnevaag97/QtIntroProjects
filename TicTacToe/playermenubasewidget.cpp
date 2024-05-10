#include "playermenubasewidget.h"

PlayerMenuBaseWidget::PlayerMenuBaseWidget(QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QVBoxLayout();
    //setLayout(mainLayout); This is done in the above classes.

    // Title of page.
    titleLabel = new QLabel("Who is playing?", this);
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    // Create grid
    QGridLayout *gridLayout = new QGridLayout();
    mainLayout->addLayout(gridLayout);

    // Show Player 1 and player 2 text labels.
    player1Label = new QLabel(this);
    player1Label->setAlignment(Qt::AlignCenter);
    gridLayout->addWidget(player1Label, 0, 0);

    player2Label = new QLabel();
    player2Label->setAlignment(Qt::AlignCenter);
    gridLayout->addWidget(player2Label, 0, 1);

    // Show box to write their names in.
    player1Input = new QLineEdit(this);
    player1Input->setAlignment(Qt::AlignCenter);
    gridLayout->addWidget(player1Input, 1, 0);

    player2Input = new QLineEdit(this);
    player2Input->setAlignment(Qt::AlignCenter);
    gridLayout->addWidget(player2Input, 1, 1);

    // Drop down menu
    dropDownButton1 = new QPushButton();
    dropDownButton1->setText("▼"); // You can set an icon or any text for the button
    dropDownButton1->setFixedSize(20, 20);

    dropDownButton2 = new QPushButton();
    dropDownButton2->setText("▼"); // You can set an icon or any text for the button
    dropDownButton2->setFixedSize(20, 20);

    // Connect the button's clicked signal to show the dropdown menu
    connect(dropDownButton1, &QPushButton::clicked, this, &PlayerMenuBaseWidget::showDropDownMenu1);
    connect(dropDownButton2, &QPushButton::clicked, this, &PlayerMenuBaseWidget::showDropDownMenu2);

    // Create the dropdown menu
    dropDownMenu1 = new QMenu();
    dropDownMenu2 = new QMenu();

    // Initiate file manager.
    r = new PlayerNameFileManager;

    /*
    QStringList computers = {"Easy Computer"};
    for (const QString &name : computers) {
        QAction *action2 = dropDownMenu2->addAction(name);
        connect(action2, &QAction::triggered, this, [this, name]() { player2Input->setText(name); });
    }
    */

    gridLayout->addWidget(dropDownButton1, 1, 0, Qt::AlignRight);
    gridLayout->addWidget(dropDownButton2, 1, 1, Qt::AlignRight);
    gridLayout->setContentsMargins(0, 0, 0, 0); // I don't know what this one does.

    QBoxLayout *buttonLayout = new QBoxLayout(QBoxLayout::Direction::TopToBottom);
    mainLayout->addLayout(buttonLayout);

    // Continue to game button
    startGameButton = new QPushButton();
    startGameButton->setText("Start Game");
    startGameButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    buttonLayout->addWidget(startGameButton);

    connect(startGameButton,
            &QPushButton::clicked,
            this,
            &PlayerMenuBaseWidget::startGameButtonClicked);

    // Continue to game button
    returnToMenuButton = new QPushButton();
    returnToMenuButton->setText("Back");
    returnToMenuButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    buttonLayout->addWidget(returnToMenuButton);

    connect(returnToMenuButton,
            &QPushButton::clicked,
            this,
            &PlayerMenuBaseWidget::returnToMenuClicked);
}

void PlayerMenuBaseWidget::startGameButtonClicked()
{
    sendPlayerNames();
    emit startGame();
}

void PlayerMenuBaseWidget::returnToMenuClicked()
{
    emit returnToMenu();
}

void PlayerMenuBaseWidget::sendPlayerNames()
{
    QString player1_name = player1Input->text();
    player1Input->clear();
    QString player2_name = player2Input->text();
    player2Input->clear();

    QVector<QString> names = {player1_name, player2_name};
    r->saveNamesToFile(names);

    emit setPlayerNames(player1_name, player2_name);
}

void PlayerMenuBaseWidget::showDropDownMenu1()
{
    dropDownMenu1->clear();
    QVector<QString> names = r->loadNamesFromFile();
    for (const QString &name : names) {
        QAction *action1 = dropDownMenu1->addAction(name);
        connect(action1, &QAction::triggered, this, [this, name]() { player1Input->setText(name); });
    }

    // Show the dropdown menu below the dropdown button
    dropDownMenu1->exec(dropDownButton1->mapToGlobal(
        QPoint(-(dropDownButton1->width() * 5), dropDownButton1->height())));
}

void PlayerMenuBaseWidget::showDropDownMenu2()
{
    // Show the dropdown menu below the dropdown button
    dropDownMenu2->exec(dropDownButton2->mapToGlobal(
        QPoint(-(dropDownButton1->width() * 5), dropDownButton2->height())));
}
