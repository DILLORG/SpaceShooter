#include <QtTest>

// add necessary includes here

class spaceShooterTest : public QObject
{
    Q_OBJECT

public:
    spaceShooterTest();
    ~spaceShooterTest();

private slots:
    void test_case1();

};

spaceShooterTest::spaceShooterTest(){

}

spaceShooterTest::~spaceShooterTest(){

}

void spaceShooterTest::test_case1(){

}

QTEST_APPLESS_MAIN(spaceShooterTest)

#include "tst_spaceshootertest.moc"
