#ifndef PLAYERNAMEFILEMANAGER_H
#define PLAYERNAMEFILEMANAGER_H

#include <QFile>
#include <QTextStream>
#include "QString"
#include "QVector"

class PlayerNameFileManager
{
public:
    PlayerNameFileManager();
    void saveNamesToFile(const QVector<QString> &names);
    QVector<QString> loadNamesFromFile();
    void clearNamesInFile();
    void deleteFile();
    bool nameExist(QString name);

private:
    const QString filename = "players.txt";
};

#endif // PLAYERNAMEFILEMANAGER_H
