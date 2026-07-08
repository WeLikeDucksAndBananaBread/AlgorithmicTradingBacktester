#include <QObject>
#include <QtTest/QtTest>

class RuleParserTests : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testParse();

};

void RuleParserTests::initTestCase()
{
}

void RuleParserTests::cleanupTestCase()
{
}

void RuleParserTests::testParse()
{
    QVERIFY(true);
}

QTEST_MAIN(RuleParserTests)
#include "RuleParserTests.moc"
