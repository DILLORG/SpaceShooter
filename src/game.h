#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTimer>
#include "sprite.h"

class Game : public QGraphicsView{
Q_OBJECT
private slots:
    void onGenerate();
private:
    QGraphicsScene* scene;
    QTimer* animationTimer;
    QTimer* genratorTimer;
    int highScore;
    Player* player;
public:
    Game();
    bool newHighScore();
    ~Game(){};
};

#endif // GAMEWINDOW_H
