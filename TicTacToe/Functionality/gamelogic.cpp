#include "gamelogic.h"

GameLogic::GameLogic()
{
    r = new PlayerDataFileManager;
    easyComputer = new EasyComputer();
    oneLevelComputer = new OneLevelComputer();
    twoLayerComputer = new TwoLayerComputer();
    invinciComputer = new InvinciComputer();
}

void GameLogic::resetGame()
{
    state.resetGameState();
    emit gameCompleted();
}

bool GameLogic::isLegalMove(Box *box)
{
    if (state.isBoxMarked(box)) {
        qWarning("Box is marked: You can't press there!");
        return false;
    }
    return true;
}

void GameLogic::nextTurn()
{
    // Update game state
    updatePlayerTurn();

    // Update text label on board.
    QString updatedTextLabel = QString("Player %1 (%2) to play.")
                                   .arg(state.getActivePlayer().getPlayerName())
                                   .arg(state.getActivePlayer().getPlayerMark());
    emit updateTextLabel(updatedTextLabel);
}

void GameLogic::buttonPressed(Box *box)
{
    if (!isLegalMove(box)) {
        return;
    }

    // Update box text
    QString updatedBoxLabel = QString("%1").arg(state.getActivePlayer().getPlayerMarkString());
    emit updateBoxText(updatedBoxLabel);

    // Update game state.
    state.setBoxState(std::get<0>(box->location), std::get<1>(box->location));

    // Check if we have a winner
    if (state.checkWinner()) {
        QMessageBox::information(nullptr,
                                 QObject::tr("Game over!"),
                                 QObject::tr("Winner winner! Player: %1 Won")
                                     .arg(state.getActivePlayer().getPlayerName()));
        // Update winner and loser data.
        r->updatePlayerDataInFile(state.getActivePlayer().getPlayerName(), {1, 1, 0, 0});
        r->updatePlayerDataInFile(state.getInActivePlayer().getPlayerName(), {1, 0, 1, 0});
        resetGame();
        return;
    }

    nextTurn();
    if (state.checkTie()) {
        QMessageBox::information(nullptr, QObject::tr("Game over!"), QObject::tr("It's a tie!"));

        r->updatePlayerDataInFile(state.getActivePlayer().getPlayerName(), {1, 0, 0, 1});
        r->updatePlayerDataInFile(state.getInActivePlayer().getPlayerName(), {1, 0, 0, 1});
        resetGame();
        return;
    }

    if ((gameMode == Singleplayer) && (state.getActivePlayer().getPlayerMark() == PlayerMark::O)) {
        qDebug("Computer to play.");
        int move = computer->makeMove(&state);
        if (move == -1) {
            qWarning("Computer made an invalid move!");
            return;
        }
        emit computerMove(move);
    }
}

void GameLogic::setPlayerNames(QString p1, QString p2)
{
    state.setPlayerNames(p1, p2);

    if (gameMode == Singleplayer) {
        setComputer(p2);
    }

    QString s = QString("Player %1 (X) starts the game.").arg(state.getPlayer(1).getPlayerName());
    emit updateTextLabel(s);
}

void GameLogic::setGameMode(GameMode mode)
{
    if (mode != GameMode::Singleplayer && mode != GameMode::Multiplayer) {
        qWarning("Unknown game mode!");
        return;
    }
    gameMode = mode;
    if (gameMode == Singleplayer) {
        //computer = computerPtr;
    }
}

void GameLogic::setComputer(QString computerName)
{
    if (computerName == "Easy Computer") {
        computer = easyComputer;
    } else if (computerName == "Smart Computer") {
        computer = oneLevelComputer;
    } else if (computerName == "Smarter Computer") {
        computer = twoLayerComputer;
        qInfo("Smarter computer choosen.");
    } else if (computerName == "Invinci Computer") {
        computer = invinciComputer;
        qInfo("Invinci computer choosen.");
    }
}

void GameLogic::updatePlayerTurn()
{
    state.switchActivePlayer();
}

QVector<int> GameLogic::getLegalMoves()
{
    return state.getUnmarkedBoxes();
}
