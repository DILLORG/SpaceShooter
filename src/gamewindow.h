#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include "sprite.h"
class GameWindow{
private:
    int highScore;
    Player* player;
public:
    GameWindow(Player* player, int hs);
    bool newHighScore();
};

#endif // GAMEWINDOW_H
