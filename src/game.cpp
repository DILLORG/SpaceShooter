#include "game.h"
#include "config.h"
Game::Game(){
    this -> highScore = 20;
    player = new Player();
    scene = new QGraphicsScene();

    player->setRect(0,0, PLAYER_WIDTH, PLAYER_HEIGHT);
    player->setFocus();
    player->setPos(this->width()/2, this->height() - player->rect().height());

    scene->addItem(player);
    scene->setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    this->setScene(scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    this->setWindowTitle(GAME_NAME);
}

bool Game::newHighScore(){
    if(player -> getScore() > this -> highScore)
        return true;
    return false;
}

void Game::onGenerate(){

}
