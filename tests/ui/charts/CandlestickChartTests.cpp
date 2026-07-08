#include <QObject>
#include <QtTest/QtTest>
#include <QtWidgets>

class CandlestickChartTests : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testChart();

};

void CandlestickChartTests::initTestCase()
{
}

void CandlestickChartTests::cleanupTestCase()
{
}

void CandlestickChartTests::testChart()
{
    QVERIFY(true);
}

QTEST_MAIN(CandlestickChartTests)
#include "CandlestickChartTests.moc"
