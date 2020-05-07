#include <QtTest>
#include "sprite.h"
#include "game.h"
#include "game.cpp"
#include "guielement.h"
#include "guielement.cpp"
// add necessary includes here

class SpaceShooterTest : public QObject
{
    Q_OBJECT

public:
    SpaceShooterTest();
    ~SpaceShooterTest();

private slots:
    void test_high_score();

};

SpaceShooterTest::SpaceShooterTest()
{

}

SpaceShooterTest::~SpaceShooterTest()
{

}

void SpaceShooterTest::test_high_score(){

//    for(int i=0; i < 20; i++){
//        game->score->increaseScore();
//    }



}

QTEST_APPLESS_MAIN(SpaceShooterTest)

#include "tst_spaceshootertest.moc"
