#include <QtTest>
#include "sprite.h"
#include "gamewindow.h"
#include "gamewindow.cpp"
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
    Player* player = new Player();
    player->addToScore(100);
    GameWindow* gameWindow = new GameWindow(player, 100);
    QVERIFY(gameWindow->newHighScore());

}

QTEST_APPLESS_MAIN(SpaceShooterTest)

#include "tst_spaceshootertest.moc"
