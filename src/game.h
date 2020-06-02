#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "sprite.h"
#include "guielement.h"
class Game : public QGraphicsView{
Q_OBJECT
private slots:
    void spawn();
    void drawStarField();
    void exitGame(){exit(0);};
    void update();
    void checkCollisions();
    void draw();
private:
    int highScore;
    QGraphicsScene* scene;
    Player* player;
    QList <Bullet*> bullets;
    QList <Star*> stars;
    QList<Enemy*> enemies;
    QList<Explosion*> explosions;
    QSound* sfx;
    QTimer* starSpawnTimer;
    QTimer* enemySpawnTimer;
    QTimer* updateTimer;
    QTimer* drawTimer;
    QTimer* collisionTimer;
    QTimer* gameOverTimer;
    Game();
    static Game* p_Instance;

public:
    Score* score;
    static Game* instance(){
        if(p_Instance==0){
            p_Instance = new Game();
        }
        return p_Instance;
    }
    bool newHighScore();
    void keyPressEvent(QKeyEvent* event);
    void initStarField();
    void gameOver();
    void playSound(QString path);


};
typedef Game TheGame;
#endif // GAMEWINDOW_H
