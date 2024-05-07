#ifndef BOX_H
#define BOX_H

#include <tuple>
#include <QObject>
#include <QWidget>
#include <QPushButton>

class Box : public QPushButton
{
    Q_OBJECT
public:
    explicit Box(int row, int col, QPushButton *parent = nullptr);

    //int player;
    int height = 100;
    int width = 100;

    std::tuple<int, int> location;
};

#endif // BOX_H
