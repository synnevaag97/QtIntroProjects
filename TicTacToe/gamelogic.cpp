#include "gamelogic.h"

GameLogic::GameLogic() {}

void GameLogic::restart()
{
    state.reset();
    emit gameCompleted();
}

bool GameLogic::isLegalMove(Box *box)
{
    if (state.isBoxMarked(box)) {
        qWarning("Box is marked: You can't press there!");
        return false;
    }
    //qDebug("The box is legal");
    return true;
}

void GameLogic::nextTurn()
{
    state.updatePlayerTurn();

    QString s = QString("Player %1 (%2) to play.")
                    .arg(state.getCurrentPlayerName())
                    .arg(state.getCurrentPlayerMark());
    qInfo("%s", state.getCurrentPlayerName().toLatin1().constData());
    emit updateTextLabel(s);
}

void GameLogic::buttonPressed(Box *box)
{
    /* Process the move just played. 
     * */

    // Check if legal move.
    if (!isLegalMove(box)) {
        return;
    }

    // Update box text
    QString s = QString("%1").arg(state.getCurrentPlayerMark());
    emit updateBoxText(s);

    // Update gameState.
    state.updateGameState(box);

    // Check if winner.
    if (state.checkWinner()) {
        QMessageBox::information(nullptr,
                                 QObject::tr("Game over!"),
                                 QObject::tr("Winner winner! Player: %1 Won")
                                     .arg(state.getCurrentPlayerName()));

        restart();
        return;
    }

    nextTurn();
    if (state.checkTie()) {
        QMessageBox::information(nullptr, QObject::tr("Game over!"), QObject::tr("It's a tie!"));
        restart();
        return;
    }

    if ((gameMode == Single) && (state.getCurrentPlayerMark() == "O")) {
        qInfo("Computer turn");
        QVector<int> legalMoves = state.getLegalMoves();
        int move = computer.makeMove(legalMoves);
        emit computerMove(move);
    }

    //qDebug("Went through all pressed process.");
}

void GameLogic::setPlayerNames(QString p1, QString p2)
{
    state.setPlayerNames(p1, p2);
    QString s = QString("Player %1 (X) starts the game.").arg(state.getPlayerName(1));
    emit updateTextLabel(s);
}

void GameLogic::setGameMode(GameMode mode)
{
    gameMode = mode;
}
