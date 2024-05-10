#include "singleplayermenuwidget.h"

SinglePlayerMenuWidget::SinglePlayerMenuWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    // Title of page.
    titleLabel = new QLabel();
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setText("Who is playing?");
    mainLayout->addWidget(titleLabel);

    // Create grid
    QGridLayout *gridLayout = new QGridLayout();
    mainLayout->addLayout(gridLayout);

    // Show Player 1 and player 2 text labels.
    player1Label = new QLabel();
    player1Label->setAlignment(Qt::AlignCenter);
    player1Label->setText("Player 1: ");
    gridLayout->addWidget(player1Label, 0, 0);

    player2Label = new QLabel();
    player2Label->setAlignment(Qt::AlignCenter);
    player2Label->setText("Computer: ");
    gridLayout->addWidget(player2Label, 0, 1);

    // Show box to write their names in.
    player1 = new QLineEdit();
    player1->setAlignment(Qt::AlignCenter);
    player1->setPlaceholderText("Enter your name");
    gridLayout->addWidget(player1, 1, 0);

    player2 = new QLineEdit();
    player2->setAlignment(Qt::AlignCenter);
    player2->setPlaceholderText("Choose computer");
    player2->setEnabled(false);
    gridLayout->addWidget(player2, 1, 1);

    // Drop down menu
    dropDownButton1 = new QPushButton();
    dropDownButton1->setText("▼"); // You can set an icon or any text for the button
    dropDownButton1->setFixedSize(20, 20);

    dropDownButton2 = new QPushButton();
    dropDownButton2->setText("▼"); // You can set an icon or any text for the button
    dropDownButton2->setFixedSize(20, 20);

    // Connect the button's clicked signal to show the dropdown menu
    connect(dropDownButton1,
            &QPushButton::clicked,
            this,
            &SinglePlayerMenuWidget::showDropDownMenu1);
    connect(dropDownButton2,
            &QPushButton::clicked,
            this,
            &SinglePlayerMenuWidget::showDropDownMenu2);

    // Create the dropdown menu
    dropDownMenu1 = new QMenu();
    dropDownMenu2 = new QMenu();
    r = new PlayerNameFileManager;
    //r->clearNamesInFile();

    QStringList computers = {"Easy Computer"};
    for (const QString &name : computers) {
        QAction *action2 = dropDownMenu2->addAction(name);
        connect(action2, &QAction::triggered, this, [this, name]() { player2->setText(name); });
    }

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
            &SinglePlayerMenuWidget::startGameButtonClicked);

    // Continue to game button
    returnToMenuButton = new QPushButton();
    returnToMenuButton->setText("Back");
    returnToMenuButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    buttonLayout->addWidget(returnToMenuButton);

    connect(returnToMenuButton,
            &QPushButton::clicked,
            this,
            &SinglePlayerMenuWidget::returnToMenuClicked);
}

void SinglePlayerMenuWidget::startGameButtonClicked()
{
    // Code for handling button click...
    sendPlayerNames();
    emit startSinglePlayerGame(); // Emit the signal when the button is clicked

    // Should i send the input names through the emit?? We want the name in the gameLogic. And let's say that the gameLogic is the one that communicate with the scoreboard.
}

void SinglePlayerMenuWidget::returnToMenuClicked()
{
    emit returnToMenu();
}

void SinglePlayerMenuWidget::sendPlayerNames()
{
    QString player1_name = player1->text();
    player1->clear();
    QString player2_name = player2->text();
    player2->clear();

    QVector<QString> names = {player1_name};
    r->saveNamesToFile(names);

    emit setPlayerNames(player1_name, player2_name);
}

void SinglePlayerMenuWidget::showDropDownMenu1()
{
    // Add some example names to the dropdown menu
    dropDownMenu1->clear();
    QVector<QString> names = r->loadNamesFromFile();
    //QStringList names = {"Alice", "Bob", "Charlie", "David"};
    for (const QString &name : names) {
        QAction *action1 = dropDownMenu1->addAction(name);
        connect(action1, &QAction::triggered, this, [this, name]() { player1->setText(name); });
    }

    // Show the dropdown menu below the dropdown button
    dropDownMenu1->exec(dropDownButton1->mapToGlobal(
        QPoint(-(dropDownButton1->width() * 5), dropDownButton1->height())));
}

void SinglePlayerMenuWidget::showDropDownMenu2()
{
    // Show the dropdown menu below the dropdown button
    dropDownMenu2->exec(dropDownButton2->mapToGlobal(
        QPoint(-(dropDownButton1->width() * 5), dropDownButton2->height())));
}
