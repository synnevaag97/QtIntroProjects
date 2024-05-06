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
    int height = 100;
    int width = 100;
};

#endif // BOX_H
