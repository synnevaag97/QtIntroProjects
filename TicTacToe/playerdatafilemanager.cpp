#include "playerdatafilemanager.h"
#include "qdebug.h"

PlayerDataFileManager::PlayerDataFileManager() {}

void PlayerDataFileManager::addNewPlayersToFile(const QVector<QString> &newNames)
{
    /* Add new players and all stats are set to zero. */

    QVector<QString> existingNames = loadPlayerNamesFromFile();
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        for (const QString &name : newNames) {
            if (!existingNames.contains(name)) {
                out << name << "\n";
                out << 0 << " " << 0 << " " << 0 << " " << 0 << "\n"; // [Played, Won, Lost, Tied]
            }
        }
    }
    file.close();
}

QVector<QString> PlayerDataFileManager::loadPlayerNamesFromFile()
{
    QVector<QString> names;
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString name = in.readLine().trimmed();
            names.push_back(name);

            // Skip the next line
            in.readLine();
        }
        file.close();
    }
    return names;
}

void PlayerDataFileManager::savePlayerDataToFile(QVector<QPair<QString, QVector<int>>> newData)
{
    clearFile();

    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        for (const auto &playerData : newData) {
            // Extract player name and stats
            const QString &name = playerData.first;
            const QVector<int> &stats = playerData.second;
            out << name << "\n";
            for (const int &stat : stats) {
                out << stat << " ";
            }
            out << "\n";
        }
        file.close();
    }
}

void PlayerDataFileManager::updatePlayerDataInFile(const QString &playerName,
                                                   const QVector<int> &newStats)
{
    QVector<QPair<QString, QVector<int>>> playerData = loadPlayerDataFromFile();

    // Find the player in the loaded data and update their stats
    for (auto &player : playerData) {
        if (player.first == playerName) {
            QVector<int> updatedStats = player.second;
            if (!(updatedStats.size() == newStats.size())) {
                qWarning() << "Incorrect sizes";
                return;
            }
            // Perform element-wise addition
            for (int i = 0; i < updatedStats.size(); ++i) {
                updatedStats[i] += newStats[i];
            }
            player.second = updatedStats;
            break; // No need to continue searching
        }
    }

    // Write the updated player data back to the file
    savePlayerDataToFile(playerData);
}

QVector<QPair<QString, QVector<int>>> PlayerDataFileManager::loadPlayerDataFromFile()
{
    QVector<QPair<QString, QVector<int>>> playerData;
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString name = in.readLine().trimmed();
            QVector<int> stats;
            QStringList statList = in.readLine().trimmed().split(" ", Qt::SkipEmptyParts);
            for (const QString &stat : statList) {
                stats.append(stat.toInt());
            }
            playerData.append(qMakePair(name, stats));
        }
        file.close();
    }
    return playerData;
}

void PlayerDataFileManager::clearFile()
{
    // Clear/Remove all data in the file.
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        file.close();
    }
}

void PlayerDataFileManager::deleteFile()
{
    // Delete file
    QFile file(filename);
    if (file.exists()) {
        file.remove();
    }
}
