#include "playernamefilemanager.h"

PlayerNameFileManager::PlayerNameFileManager() {}

void PlayerNameFileManager::saveNamesToFile(const QVector<QString> &newNames)
{
    QVector<QString> existingNames = loadNamesFromFile();
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        for (const QString &name : newNames) {
            if (!existingNames.contains(name)) {
                out << name << "\n";
            }
        }
        file.close();
    }
}

QVector<QString> PlayerNameFileManager::loadNamesFromFile()
{
    QVector<QString> names;
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString name = in.readLine();
            names.push_back(name);
        }
        file.close();
    }
    return names;
}

void PlayerNameFileManager::clearNamesInFile()
{
    // Clear/Remove all names in the file.
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        file.close();
    }
}

void PlayerNameFileManager::deleteFile()
{
    // Delete file
    QFile file(filename);
    if (file.exists()) {
        file.remove();
    }
}
