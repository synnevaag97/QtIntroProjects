#ifndef SINGLEPLAYERMENUWIDGET_H
#define SINGLEPLAYERMENUWIDGET_H

#include <QBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QWidget>

#include "playerdatafilemanager.h"
#include "playermenubasewidget.h"

class SinglePlayerMenuWidget : public PlayerMenuBaseWidget
{
    Q_OBJECT
public:
    explicit SinglePlayerMenuWidget(PlayerMenuBaseWidget *parent = nullptr);

    void sendPlayerNames() override;
};

#endif // SINGLEPLAYERMENUWIDGET_H
