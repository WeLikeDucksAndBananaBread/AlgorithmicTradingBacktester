#include <QObject>
#include <QtTest/QtTest>
#include "data/parsers/csv_parser.h"

using namespace backtester::data;

class CSVParserTests : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testParse();

};

void CSVParserTests::initTestCase()
{
}

void CSVParserTests::cleanupTestCase()
{
}

void CSVParserTests::testParse()
{
    CsvParser parser;
    QVERIFY(true); // Replace with actual test
}

QTEST_MAIN(CSVParserTests)
#include "CSVParserTests.moc"
