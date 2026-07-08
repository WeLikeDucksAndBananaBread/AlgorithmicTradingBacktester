#include <QObject>
#include <QtTest/QtTest>

#include "data/parsers/csv_parser.h"

using backtester::data::CsvParser;

class CSVParserTests : public QObject {
  Q_OBJECT

 private slots:
  void initTestCase();
  void cleanupTestCase();
  static void testParse();
};

void CSVParserTests::initTestCase() {}

void CSVParserTests::cleanupTestCase() {}

void CSVParserTests::testParse() {
  CsvParser parser;
  QVERIFY(true);
}

QTEST_MAIN(CSVParserTests)
#include "CSVParserTests.moc"
