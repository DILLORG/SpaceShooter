#include <QtTest>

// add necessary includes here

class SpaceShooterTest : public QObject
{
    Q_OBJECT

public:
    SpaceShooterTest();
    ~SpaceShooterTest();

private slots:
    void test_case1();

};

SpaceShooterTest::SpaceShooterTest()
{

}

SpaceShooterTest::~SpaceShooterTest()
{

}

void SpaceShooterTest::test_case1()
{

}

QTEST_APPLESS_MAIN(SpaceShooterTest)

#include "tst_spaceshootertest.moc"
