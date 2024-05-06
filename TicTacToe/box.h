#ifndef BOX_H
#define BOX_H


#include <QObject>
#include <QWidget>
#include <QPushButton>

class Box : public QPushButton
{
    Q_OBJECT
public:
    explicit Box(QPushButton *parent = nullptr);

    int player;
};

#endif // BOX_H