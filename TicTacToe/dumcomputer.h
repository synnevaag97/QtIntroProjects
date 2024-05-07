#ifndef DUMCOMPUTER_H
#define DUMCOMPUTER_H

#include <QObject>

class DumComputer : public QObject
{
    Q_OBJECT
public:
    DumComputer();
    void generateNextMove();

signals:
    void move();
};

#endif // DUMCOMPUTER_H
