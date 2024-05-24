
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

#include "converter.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    QLineEdit *input;
    QLineEdit *output;
    QPushButton *playMorseCodeButton;

    QVBoxLayout *mainLayout;
    Converter *converter;
    MorseCodeSound *morseCodeSound;

    QString textGiven;

private slots:
    void updateLabel(const QString &text);
    void playMorseCodeButtonClicked();
};
#endif // MAINWINDOW_H
