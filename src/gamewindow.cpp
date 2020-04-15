#include "gamewindow.h"

GameWindow::GameWindow(Player* player, int hs){
    this -> player = player;
    this -> highScore = hs;
}

bool GameWindow::newHighScore(){
    if(player -> getScore() > this -> highScore)
        return true;
    return false;
}
