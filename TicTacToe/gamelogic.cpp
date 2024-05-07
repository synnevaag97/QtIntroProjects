#include "gamelogic.h"

GameLogic::GameLogic() {}

void GameLogic::restart()
{
    state.reset();
    emit gameCompleted();
}

void GameLogic::nextTurn()
{
    state.updatePlayerTurn();

    QString s = QString("Player %1 (%2) to play.")
                    .arg(state.getCurrentPlayerName())
                    .arg(state.getCurrentPlayerMark());
    emit updateTextLabel(s);
}

void GameLogic::buttonPressed(Box *box)
{
    /* Process the move just played. 
     * */

    // Check if legal move.
    if (!state.isLegalMove(box)) {
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
}

void GameLogic::setPlayerNames(QString p1, QString p2)
{
    state.setPlayerNames(p1, p2);
    QString s = QString("Player %1 (X) starts the game.").arg(state.getPlayerName(1));
    emit updateTextLabel(s);
}
