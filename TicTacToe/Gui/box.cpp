
#include "box.h"

Box::Box(int row, int col, QPushButton *parent)
    : QPushButton{parent}, location{row,col}
{
    //player = -1;
    this->setMinimumHeight(height);
    this->setMinimumWidth(width);
}
