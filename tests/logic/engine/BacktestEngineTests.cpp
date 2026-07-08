#include <QObject>
#include <QtTest/QtTest>
#include "logic/engine/backtest_engine.h"

class BacktestEngineTests : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testConstruction();

private:
    BacktestEngine* engine;
};

void BacktestEngineTests::initTestCase()
{
    engine = new BacktestEngine();
}

void BacktestEngineTests::cleanupTestCase()
{
    delete engine;
}

void BacktestEngineTests::testConstruction()
{
    QVERIFY(engine != nullptr);
}

QTEST_MAIN(BacktestEngineTests)
#include "BacktestEngineTests.moc"
