
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QVBoxLayout>

#include "converter.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    QLineEdit *input;
    QLineEdit *output;

    QVBoxLayout *mainLayout;
    Converter *converter;

private slots:
    void updateLabel(const QString &text);
};
#endif // MAINWINDOW_H
