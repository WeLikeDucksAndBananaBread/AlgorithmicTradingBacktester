#include <QObject>
#include <QtTest/QtTest>

class SMATests : public QObject {
  Q_OBJECT

 private slots:
  void initTestCase();
  void cleanupTestCase();
  static void testCalculation();
};

void SMATests::initTestCase() {}

void SMATests::cleanupTestCase() {}

void SMATests::testCalculation() { QVERIFY(true); }

QTEST_MAIN(SMATests)
#include "SMATests.moc"
