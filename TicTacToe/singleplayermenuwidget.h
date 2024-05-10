#ifndef SINGLEPLAYERMENUWIDGET_H
#define SINGLEPLAYERMENUWIDGET_H

#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QWidget>

#include "playermenubasewidget.h"
#include "playernamefilemanager.h"

class SinglePlayerMenuWidget : public PlayerMenuBaseWidget
{
    Q_OBJECT
public:
    explicit SinglePlayerMenuWidget(PlayerMenuBaseWidget *parent = nullptr);
};

#endif // SINGLEPLAYERMENUWIDGET_H
