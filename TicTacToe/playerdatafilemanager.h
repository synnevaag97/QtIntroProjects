#ifndef PLAYERDATAFILEMANAGER_H
#define PLAYERDATAFILEMANAGER_H

#include <QFile>
#include <QString>
#include <QTextStream>
#include <QVector>
#include <QtLogging> //

class PlayerDataFileManager
{
public:
    PlayerDataFileManager();

    QVector<QString> loadPlayerNamesFromFile();
    void addNewPlayersToFile(const QVector<QString> &names);

    void updatePlayerDataInFile(const QString &playerName, const QVector<int> &newStats);
    QVector<QPair<QString, QVector<int>>> loadPlayerDataFromFile();
    void clearFile();
    void deleteFile();

private:
    const QString filename = "players.txt";
    void savePlayerDataToFile(QVector<QPair<QString, QVector<int>>>);
};

#endif // PLAYERDATAFILEMANAGER_H
