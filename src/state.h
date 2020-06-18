#ifndef STATE_H
#define STATE_H
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include "sprite.h"
#include "guielement.h"
class State : public QGraphicsScene
{
Q_OBJECT
public:
    State();
    ~State(){};
};

class PlayState : public State{
    Q_OBJECT
private slots:
    void update();
    void draw();
    void checkCollisions();
    void spawn();
    void drawStarField();
private:
    QTimer* starSpawnTimer;
    QTimer* enemySpawnTimer;
    QTimer* updateTimer;
    QTimer* drawTimer;
    QTimer* collisionTimer;
    Player* player;
    Score* score;
    QList <Bullet*> bullets;
    QList <Star*> stars;
    QList <Enemy*> enemies;
    QList <Explosion*> explosions;

public:
    PlayState();
    void keyPressEvent(QKeyEvent* event) override;
    void initStarField();
    ~PlayState(){};
};

class GameOverState : public State{
Q_OBJECT
private slots:
    void replayClick();
private:
    TextElement* gameOverLbl;
    Button* replayButton;
public:
    GameOverState();
    ~GameOverState(){};
};
class MenuState : public State{
  Q_OBJECT
private slots:
  void playClick();
private:
  Button* playButton;
public:
    MenuState();
    ~MenuState(){};
};

#endif // STATE_H
