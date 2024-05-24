#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Morse Converter");
    setGeometry(0, 0, 400, 400);

    QWidget *centralWidget = new QWidget;
    setCentralWidget(centralWidget);

    mainLayout = new QVBoxLayout();
    centralWidget->setLayout(mainLayout);

    // Create a group box for the input and output fields
    QGroupBox *groupBox = new QGroupBox("Morse Code Converter", this);
    QFormLayout *formLayout = new QFormLayout();

    // Create one text box for input text.
    input = new QLineEdit(this);
    formLayout->addRow("Input:", input);
    input->setPlaceholderText("Type text or Morse code");

    // Create one text box to display, and should not be written to.
    output = new QLineEdit(this);
    output->setPlaceholderText("The translated message appears here.");
    formLayout->addRow("Output:", output);
    output->setEnabled(false);

    groupBox->setLayout(formLayout);
    mainLayout->addWidget(groupBox);

    playMorseCodeButton = new QPushButton("Play morse code");
    playMorseCodeButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    mainLayout->addWidget(playMorseCodeButton, 0, Qt::AlignCenter);

    connect(input, &QLineEdit::textChanged, this, &MainWindow::updateLabel);
    connect(playMorseCodeButton,
            &QPushButton::clicked,
            this,
            &MainWindow::playMorseCodeButtonClicked);

    converter = new Converter();
    morseCodeSound = new MorseCodeSound();
}

void MainWindow::updateLabel(const QString &text)
{
    // Convert toUppper and then send.
    output->setText(converter->convert(text.toUpper()));
    textGiven = output->text();
}

void MainWindow::playMorseCodeButtonClicked()
{
    for (int i = 0; i < textGiven.length(); i++) {
        morseCodeSound->playMorseCode(QChar{textGiven[i]});
    }
}
