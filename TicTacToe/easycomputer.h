#ifndef EASYCOMPUTER_H
#define EASYCOMPUTER_H

#include <QRandomGenerator>
#include <QVector>

class EasyComputer
{
public:
    EasyComputer();
    int makeMove(QVector<int> legalMoves);
};

#endif // EASYCOMPUTER_H
