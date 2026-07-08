#include <QObject>
#include <QtTest/QtTest>
#include "data/cache/DataCache.h"

using namespace backtester::data;

class DataCacheTests : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testCache();

};

void DataCacheTests::initTestCase()
{
}

void DataCacheTests::cleanupTestCase()
{
}

void DataCacheTests::testCache()
{
    DataCache cache;
    QVERIFY(true); // Replace with actual test
}

QTEST_MAIN(DataCacheTests)
#include "DataCacheTests.moc"
