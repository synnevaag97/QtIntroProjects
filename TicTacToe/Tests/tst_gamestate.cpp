#include "tst_gamestate.h"

/*
// Define a separate function to handle assertion messages
void assertionMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(type);
    Q_UNUSED(context);
    if (msg.startsWith("ASSERT:")) {
        qDebug() << "Assertion caught:" << msg;
        QTest::qFail("Assertion triggered", __FILE__, __LINE__);
    }
}*/

void TestGameState::init()
{
    gameState = new GameState();

    // Test the initiated state. Expected 3x3 matrix with elements set to -1.
    QVector<QVector<int>> boardState = gameState->getBoardState();
    QVERIFY(boardState.size() == 3);
    QVERIFY(boardState[0].size() == 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            QVERIFY(boardState[i][j] == -1);
        }
    }

    // Expect player 1 to start.
    Player currentPlayer = gameState->getActivePlayer();
    QVERIFY(currentPlayer.getPlayerMark() == PlayerMark::X);

    // Expect two empty names.
    QVector<Player> players = gameState->getPlayers();
    QVERIFY(players.size() == 2);
    QVERIFY(players[0].getPlayerName().isEmpty());
    QVERIFY(players[1].getPlayerName().isEmpty());
}
/*
void TestGameState::setBoxState()
{
    // Connect the custom assertion message handler
    qInstallMessageHandler(assertionMessageHandler);
    assertionCaught = false;

    GameState *gameState = new GameState();

    gameState->setBoxState(1, 1);
    QVector<QVector<int>> boardState = gameState->getBoardState();
    QVERIFY(boardState[1][1] == PlayerMark::X);

    //QTest::ignoreMessage(QtDebugMsg, "Invalid row or column value");
    gameState->setBoxState(3, 3);
    // Assert that the assertion was caught
    QVERIFY(assertionCaught);
    assertionCaught = false; // Reset for the next test
}*/

void TestGameState::setPlayerNames()
{
    // Expect two empty names.
    QVector<Player> players = gameState->getPlayers();
    QVERIFY(players.size() == 2);
    QVERIFY(players[0].getPlayerName().isEmpty());
    QVERIFY(players[1].getPlayerName().isEmpty());

    // Expect two empty names.
    gameState->setPlayerNames("Trym1", "Trym2");
    players = gameState->getPlayers();
    QVERIFY(players.size() == 2);
    QVERIFY(!players[0].getPlayerName().isEmpty());
    QVERIFY(!players[1].getPlayerName().isEmpty());
}

void TestGameState::switchActivePlayer()
{
    Player activePlayer = gameState->getActivePlayer();
    QVERIFY(activePlayer.getPlayerMark() == PlayerMark::X);

    gameState->switchActivePlayer();
    activePlayer = gameState->getActivePlayer();
    QVERIFY(activePlayer.getPlayerMark() == PlayerMark::O);
}

void TestGameState::resetGameState()
{
    gameState->resetGameState();
    QVector<QVector<int>> boardState = gameState->getBoardState();
    QVector<Player> players = gameState->getPlayers();

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            QVERIFY(boardState[i][j] == -1);
        }
    }
    QVERIFY(players[0].getPlayerName() == "");
    QVERIFY(players[1].getPlayerName() == "");

    QVERIFY(gameState->getActivePlayer().getPlayerMark() == PlayerMark::X);
}

void TestGameState::getUnmarkedBoxes()
{
    QVector<int> unmarkedBoxes = gameState->getUnmarkedBoxes();
    QVERIFY(unmarkedBoxes.size() == 9);
}

void TestGameState::getBoardState()
{
    QVector<QVector<int>> boardState = gameState->getBoardState();
    QVERIFY(boardState.size() == 3);
    QVERIFY(boardState[0].size() == 3);
}

void TestGameState::getPlayers()
{
    QVector<Player> players = gameState->getPlayers();
    QVERIFY(players.size() == 2);
}

void TestGameState::getPlayer()
{
    Player player = gameState->getPlayer(1);
    QVERIFY(player.getPlayerMark() == PlayerMark::X);

    player = gameState->getPlayer(2);
    QVERIFY(player.getPlayerMark() == PlayerMark::O);
}

void TestGameState::getActivePlayer()
{
    Player player = gameState->getActivePlayer();
    QVERIFY(player.getPlayerMark() == PlayerMark::X);
}

void TestGameState::getInActivePlayer()
{
    Player player = gameState->getInActivePlayer();
    QVERIFY(player.getPlayerMark() == PlayerMark::O);
}

/*
void TestGameState::handleAssertion(const QString &message)
{
    qDebug() << "Assertion caught:" << message;
    assertionCaught = true;
}*/

// Macro generating main function for test executable.
// When you include QTEST_MAIN(TestQString) in your test source file,
// it expands to a main function that sets up the Qt Test framework
// and runs all the test functions defined in your test class.
//QTEST_MAIN(TestGameState)

// The #include "tst_init.moc" line is used to include the meta-object compiler (moc) output file for your test class.
// The moc is responsible for generating code that enables Qt's meta-object system,
// which is used for features like signals and slots,
// introspection, and dynamic properties.
//#include "tst_gamestate.moc"
//#include "tst_player.moc"
