#include "gamelogic.h"

GameLogic::GameLogic() {
    gameState.resize(3);
    for (int i = 0; i < 3; ++i) {
        gameState[i].resize(3);
    }
    init();
}

void GameLogic::init(){

    marked_tiles = 0;
    whos_turn = 1;

    // Initialize all elements to -1
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            gameState[i][j] = -1;
        }
    }
}


bool GameLogic::checkWinner(Box *buttonClicked){
    // When on click check if we have a winner.
    bool finished = false;

    // Determine which button was clicked
    if (buttonClicked->location == std::tuple<int,int>(0,0)) {
        // Check row1, col1 and diag1
        int player_mark = whos_turn;
        if(checkRow1(player_mark))return true;
        if(checkCol1(player_mark))return true;
        if(checkDiag1(player_mark))return true;

    } else if (buttonClicked->location == std::tuple<int,int>(0,1)) {
        // Check row1, col2
        int player_mark = whos_turn;
        if(checkRow1(player_mark))return true;
        if(checkCol2(player_mark))return true;

    } else if (buttonClicked->location == std::tuple<int,int>(0,2)) {
        // Check row1, col3 and diag2
        int player_mark = whos_turn;
        if(checkRow1(player_mark))return true;
        if(checkCol3(player_mark))return true;
        if(checkDiag2(player_mark))return true;

    } else if (buttonClicked->location == std::tuple<int,int>(1,0)) {
        // Check row2, col1
        int player_mark = whos_turn;
        if(checkRow2(player_mark))return true;
        if(checkCol1(player_mark))return true;


    } else if (buttonClicked->location == std::tuple<int,int>(1,1)) {
        // Check row2, col2 and diag1 and diag 2
        int player_mark = whos_turn;
        if(checkRow2(player_mark))return true;
        if(checkCol2(player_mark))return true;
        if(checkDiag1(player_mark))return true;
        if(checkDiag2(player_mark))return true;

    } else if (buttonClicked->location == std::tuple<int,int>(1,2)) {
        // Check row2, col3
        int player_mark = whos_turn;
        if(checkRow2(player_mark))return true;
        if(checkCol3(player_mark))return true;

    } else if (buttonClicked->location == std::tuple<int,int>(2,0)) {
        // Check row3, col1 and diag2
        int player_mark = whos_turn;
        if(checkRow3(player_mark))return true;
        if(checkCol1(player_mark))return true;
        if(checkDiag2(player_mark))return true;

    } else if (buttonClicked->location == std::tuple<int,int>(2,1)) {
        // Check row3, col2 and
        int player_mark = whos_turn;
        if(checkRow3(player_mark))return true;
        if(checkCol2(player_mark))return true;

    } else if (buttonClicked->location == std::tuple<int,int>(2,2)) {
        // Check row3, col3 and diag1
        int player_mark = whos_turn;
        if(checkRow3(player_mark))return true;
        if(checkCol3(player_mark))return true;
        if(checkDiag1(player_mark))return true;
    }

    return finished;
}

bool GameLogic::checkRow1(int player_mark){
    if ((gameState[0][0] == player_mark) &&
        (gameState[0][1] == player_mark) &&
        (gameState[0][2] == player_mark)){
        return true;
    }
    return false;
}

bool GameLogic::checkRow2(int player_mark){
    if ((gameState[1][0] == player_mark) &&
        (gameState[1][1] == player_mark) &&
        (gameState[1][2] == player_mark)){
        return true;
    }
    return false;
}

bool GameLogic::checkRow3(int player_mark){
    if ((gameState[2][0] == player_mark) &&
        (gameState[2][1] == player_mark) &&
        (gameState[2][2] == player_mark)){
        return true;
    }
    return false;
}

bool GameLogic::checkCol1(int player_mark){
    if ((gameState[0][0] == player_mark) &&
        (gameState[1][0] == player_mark) &&
        (gameState[2][0] == player_mark)){
        return true;
    }
    return false;
}

bool GameLogic::checkCol2(int player_mark){
    if ((gameState[0][1] == player_mark) &&
        (gameState[1][1] == player_mark) &&
        (gameState[2][1] == player_mark)){
        return true;
    }
    return false;
}

bool GameLogic::checkCol3(int player_mark){
    if ((gameState[0][2] == player_mark) &&
        (gameState[1][2] == player_mark) &&
        (gameState[2][2] == player_mark)){
        return true;
    }
    return false;
}

bool GameLogic::checkDiag1(int player_mark){
    if ((gameState[0][0] == player_mark) &&
        (gameState[1][1] == player_mark) &&
        (gameState[2][2] == player_mark)){
        return true;
    }
    return false;
}

bool GameLogic::checkDiag2(int player_mark){
    if ((gameState[2][0] == player_mark) &&
        (gameState[1][1] == player_mark) &&
        (gameState[0][2] == player_mark)){
        return true;
    }
    return false;
}


void GameLogic::restart(){

    init();
    emit gameCompleted();
}

void GameLogic::nextTurn(){

    if (whos_turn == 1){
        whos_turn = 2;
    } else if (whos_turn == 2){
        whos_turn = 1;
    }
    QString s = QString("Player %1 (%2) to play.").arg(whos_turn).arg(whos_turn == PlayerMark::X ? "X" : "O");
    emit updateTextLabel(s);

    marked_tiles++;
}

void GameLogic::updateGameState(Box *box){
    gameState[std::get<0>(box->location)][std::get<1>(box->location)] = whos_turn;
}

bool GameLogic::checkTie(){
    if (marked_tiles >= 9){
        return true;
    }
    return false;
}

bool GameLogic::isLegalMove(Box *box){
    if(gameState[std::get<0>(box->location)][std::get<1>(box->location)] == -1){
        return true;
    }
    return false;
}

void GameLogic::buttonPressed(Box *box){
    // Check if legal move.
    if(!isLegalMove(box)){
        return;
    }

    // Update box text
    QString s = QString("%1").arg(whos_turn == PlayerMark::X ? "X" : "O");
    emit updateBoxText(s);

    // Update gameState.
    updateGameState(box);

    // Check if winner.
    if(checkWinner(box)){
        qInfo("Winner winner chicken dinner! Player: %d Won", whos_turn);
        QMessageBox::information(
            nullptr,
            QObject::tr("Game over!"),
            QObject::tr("Winner winner chicken dinner! Player: %1 Won").arg(whos_turn) );

        restart();
        return;

    }

    // Next turn
    nextTurn();
    if(checkTie()){
        restart();

        qInfo("It's a tie!");
        QMessageBox::information(
            nullptr,
            QObject::tr("Game over!"),
            QObject::tr("It's a tie!") );
        return;
    }
}
