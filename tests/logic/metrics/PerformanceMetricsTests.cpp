#include <QObject>
#include <QtTest/QtTest>

class PerformanceMetricsTests : public QObject {
  Q_OBJECT

 private slots:
  void initTestCase();
  void cleanupTestCase();
  static void testInitialState();
};

void PerformanceMetricsTests::initTestCase() {}

void PerformanceMetricsTests::cleanupTestCase() {}

void PerformanceMetricsTests::testInitialState() { QVERIFY(true); }

QTEST_MAIN(PerformanceMetricsTests)
#include "PerformanceMetricsTests.moc"
