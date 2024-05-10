#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QFile>
#include <QTextStream>
#include "QString"
#include "QVector"

class Registration
{
public:
    Registration();
    void saveNamesToFile(const QVector<QString> &names);
    QVector<QString> loadNamesFromFile();
    void clearNamesInFile();
    void deleteFile();
    bool nameExist(QString name);

private:
    const QString filename = "players.txt";
};

#endif // REGISTRATION_H
