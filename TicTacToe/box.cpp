#include "box.h"

Box::Box(QPushButton *parent)
    : QPushButton{parent}
{
    player = -1;
    this->setMinimumHeight(height);
    this->setMinimumWidth(width);
}
