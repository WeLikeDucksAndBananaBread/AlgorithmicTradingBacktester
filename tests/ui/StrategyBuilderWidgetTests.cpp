#include <QObject>
#include <QtTest/QtTest>
#include <QtWidgets>

class StrategyBuilderWidgetTests : public QObject {
  Q_OBJECT

 private slots:
  void initTestCase();
  void cleanupTestCase();
  static void testUI();
};

void StrategyBuilderWidgetTests::initTestCase() {}

void StrategyBuilderWidgetTests::cleanupTestCase() {}

void StrategyBuilderWidgetTests::testUI() { QVERIFY(true); }

QTEST_MAIN(StrategyBuilderWidgetTests)
#include "StrategyBuilderWidgetTests.moc"
