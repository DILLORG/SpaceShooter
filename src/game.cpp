#include "game.h"
#include "config.h"
#include <stdlib.h>
Game* Game::p_Instance  = 0;
Game::Game(){

    highScore = 20;
    player = new Player();
    scene = new QGraphicsScene();
    score = new Score();
    spawnTimer = new QTimer();
    starTimer = new QTimer();
    gameOverTimer = new QTimer();

    //Create initial star field.
    Game::initStarField();
    player->setFocus();
    player->setPos(this->width()/2, this->height()/2);

    scene->addItem(player);
    scene->setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    scene->addItem(score);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    setWindowTitle(GAME_NAME);
    setBackgroundBrush(QColor(0,0,0));

    connect(starTimer, SIGNAL(timeout()), this, SLOT(drawStarField()));
    starTimer->start(STAR_SPAWN_FREQUENCY);
    connect(spawnTimer, SIGNAL(timeout()), this, SLOT(spawn()));
    spawnTimer->start(ENEMY_SPAWN_FREQUENCY);
    connect(gameOverTimer, SIGNAL(timeout()), this, SLOT(exitGame()));
}

bool Game::newHighScore(){
    if(score -> getScore() > this -> highScore)
        return true;
    return false;
}

void Game::spawn(){
    Enemy* enemy = new Enemy();
    scene->addItem(enemy);
}

void Game::initStarField(){
    for(int i=0; i< 200; i++){
        Star* star = new Star();
        star->setY(rand() % WINDOW_HEIGHT);
        star->setX(rand()% WINDOW_WIDTH);
        scene->addItem(star);
    }
}
void Game::drawStarField(){
    for(int i =0; i < NUM_STARS; i++){
        Star* star = new Star();
        scene->addItem(star);
    }
}
void Game::keyPressEvent(QKeyEvent *event){
     //Move player based on controls.
    if(event->key() == Qt::Key_A && player->pos().x() > 0){
        player->setPos(player->x() - SHIP_SPEED_FACTOR, player->y());
    }else if(event->key() == Qt::Key_D && player->pos().x() +100 < 800){
        player->setPos(player->x()+ SHIP_SPEED_FACTOR, player->y());
    }else if(event->key() == Qt::Key_W){
        player->setPos(player->x(), player->y() - SHIP_SPEED_FACTOR);
    }else if(event->key() == Qt::Key_S){
        player->setPos(player->x(), player->y() + SHIP_SPEED_FACTOR);

    //Fire bullet.
    }else if(event->key() == Qt::Key_Space){
        Bullet* bullet = new Bullet();
        bullet ->setPos(player->x(), player->y());
        bullet->setZValue(-1);
        scene->addItem(bullet);
        Game::playSound(":/assets/bullet_sound.wav");
    }
  }
void Game::gameOver(){
    if(newHighScore())
        highScore = score->getScore();

    GuiElement* gameOver = new GuiElement();
    GuiElement* highScoreMessage = new GuiElement();


    gameOver->setText(QString("GAME OVER!"));
    gameOver->setPos(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);

    highScoreMessage->setText(QString("High Score " + QString::number(highScore)));
    highScoreMessage->setPos((WINDOW_WIDTH/2) + 20, (WINDOW_HEIGHT/2) + 20);
    scene->addItem(gameOver);
    scene->addItem(highScoreMessage);
    gameOverTimer->start(200);

}

void Game::playSound(QString path){
    sfx->play(path);
}
