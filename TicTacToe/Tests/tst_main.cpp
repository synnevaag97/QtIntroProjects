// main.cpp

#include "tst_gamestate.h"
#include "tst_player.h"
#include "tst_runner.h"

int main(int argc, char *argv[])
{
    int status = 0;

    runTests<TestPlayer>(argc, argv, &status);
    runTests<TestGameState>(argc, argv, &status);

    return status;
}
