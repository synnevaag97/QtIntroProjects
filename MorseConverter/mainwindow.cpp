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

    // Create one text box for input text.
    input = new QLineEdit(this);
    input->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(input);
    input->setPlaceholderText("Type text or Morse code");

    // Create one text box to display, and should not be written to.
    output = new QLineEdit(this);
    output->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(output);
    output->setEnabled(false);
    output->setPlaceholderText("The translated message appears here.");

    connect(input, &QLineEdit::textChanged, this, &MainWindow::updateLabel);

    converter = new Converter();
}

void MainWindow::updateLabel(const QString &text)
{
    // Convert toUppper and then send.
    output->setText(converter->convert(text.toUpper()));
}
