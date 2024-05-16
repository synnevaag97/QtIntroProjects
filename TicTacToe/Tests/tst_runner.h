#ifndef TST_RUNNER_H
#define TST_RUNNER_H

// testrunner.h

#include <QtTest>

template<typename TestClass>
void runTests(int argc, char *argv[], int *status)
{
    QApplication app(argc, argv);
    app.setAttribute(Qt::AA_Use96Dpi, true);
    QTEST_DISABLE_KEYPAD_NAVIGATION TestClass tc;
    *status |= QTest::qExec(&tc, argc, argv);
}

#endif // TST_RUNNER_H
