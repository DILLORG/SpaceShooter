#include "game.h"
#include "config.h"
#include <stdlib.h>
#include <iostream>
Game* Game::p_Instance  = 0;

Game::Game(){

    highScore = 20;
    player = new Player(PLAYER_SPRITE, 50, 0, 150);
    scene = new QGraphicsScene();
    score = new Score();
    starSpawnTimer = new QTimer();
    enemySpawnTimer = new QTimer();
    updateTimer = new QTimer();
    drawTimer = new QTimer();
    collisionTimer = new QTimer();
    gameOverTimer = new QTimer();


    //Create initial star field.
    Game::initStarField();
    player->setFocus();
    player->setPos(QPointF(scene->sceneRect().center()));

    scene->addItem(player);
    scene->setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    scene->addItem(score);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    setWindowTitle(GAME_NAME);
    setBackgroundBrush(QColor(0,0,0));

    connect(starSpawnTimer, SIGNAL(timeout()), this, SLOT(drawStarField()));
    starSpawnTimer->start(STAR_SPAWN_FREQUENCY);

    connect(enemySpawnTimer, SIGNAL(timeout()), this, SLOT(spawn()));
    enemySpawnTimer->start(ENEMY_SPAWN_FREQUENCY);

    connect(updateTimer, SIGNAL(timeout()), this, SLOT(update()));
    updateTimer->start(STAR_SPEED);

    connect(drawTimer, SIGNAL(timeout()), this, SLOT(draw()));
    drawTimer->start(ANIMATION_SPEED);

    connect(collisionTimer, SIGNAL(timeout()), this, SLOT(checkCollisions()));
    collisionTimer->start(STAR_SPEED);

    connect(gameOverTimer, SIGNAL(timeout()), this, SLOT(exitGame()));

}

bool Game::newHighScore(){
    if(score -> getScore() > this -> highScore)
        return true;
    return false;
}

void Game::spawn(){
    Enemy* enemy = new Enemy(ENEMY_SPRITE, 50, 0,  150);
    scene->addItem(enemy);
    enemies.append(enemy);
}

void Game::initStarField(){
    for(int i=0; i< 200; i++){
        Star* star = new Star();
        star->setY(rand() % WINDOW_HEIGHT);
        star->setX(rand()% WINDOW_WIDTH);
        scene->addItem(star);
        stars.append(star);
    }
}

void Game::drawStarField(){
    for(int i =0; i < NUM_STARS; i++){
        Star* star = new Star();
        scene->addItem(star);
        stars.append(star);
    }
}

//Update position of game objects
void Game::update(){
    for(int i=0; i < explosions.size(); i++){
      explosions[i]->setPos(explosions[i]->x(), explosions[i]->y()+10);
      if(explosions[i]->pos().y() > WINDOW_HEIGHT){
        scene->removeItem(explosions[i]);
        explosions.removeAt(i);
      }
    }
    for(int i=0; i < enemies.size(); i++){
        enemies[i]->setPos(enemies[i]->x(), enemies[i]->y() + 5);
        if(enemies[i]->pos().y()> WINDOW_HEIGHT){
            scene->removeItem(enemies[i]);
            enemies.removeAt(i);
         }
    }

    for(int i = 0; i < bullets.size(); i++){
        bullets[i]->setPos(bullets[i]->x(), bullets[i]->y() - 10);
        if(bullets[i]->pos().y() < 0){
            scene->removeItem(bullets[i]);
            bullets.removeAt(i);
        }
    }

    for(int i =0; i < stars.size(); i++){
        stars[i]->setPos(stars[i]->x(), stars[i]->y() + 5);;
        if(stars[i]-> pos().y()> WINDOW_HEIGHT){
            scene->removeItem(stars[i]);
            stars.removeAt(i);
        }
    }
}

//Draw next frame on sprite sheet.
void Game::draw(){
    for(auto& enemy : enemies){
        enemy->draw();
    }
    for(auto& explosion : explosions){
      explosion->draw();
    }

    player->draw();
}

//Check collisions between game objects.
void Game::checkCollisions(){
    for(int i =0; i < enemies.size(); i++){
        if(enemies[i]->isHit()){
            Game::playSound(BLOW_UP);
            scene->removeItem(enemies[i]);
            Explosion* explosion = new Explosion(EXPLOSION_SPRITE, 50, 0, 150);
            explosion->setPos(enemies[i]->pos());
            explosions.append(explosion);
            enemies.removeAt(i);
            score->increaseScore();
            scene->addItem(explosion);

        }
    }

    if(player->isHit()){
        playSound(BLOW_UP);
        scene->removeItem(player);
        Explosion* explosion = new Explosion(EXPLOSION_SPRITE, 50, 0, 150);
        explosion->setPos(player->pos());
        scene->addItem(explosion);
        explosions.append(explosion);
        gameOverTimer->start(3000);
        gameOver();

    }

}

//Handle player input.
void Game::keyPressEvent(QKeyEvent *event){
     //Move player based on controls.
    if(event->key() == Qt::Key_A && player->pos().x() > 29){
        player->changeAnimation(200, 300);
        player->setPos(player->x() - SHIP_SPEED_FACTOR, player->y());
    }else if(event->key() == Qt::Key_D && player->pos().x() < WINDOW_WIDTH - 100){
        player->changeAnimation(350, 450);
        player->setPos(player->x()+ SHIP_SPEED_FACTOR, player->y());
    }else if(event->key() == Qt::Key_W && player->pos().y() > 29){
        player->changeAnimation(0, 150);
        player->setPos(player->x(), player->y() - SHIP_SPEED_FACTOR);
    }else if(event->key() == Qt::Key_S && player->pos().y() < WINDOW_HEIGHT - 100){
        player->changeAnimation(0, 150);
        player->setPos(player->x(), player->y() + SHIP_SPEED_FACTOR);

    //Fire bullet.
    }else if(event->key() == Qt::Key_Space){
        Bullet* lBullet = new Bullet();
        Bullet* rBullet = new Bullet();
        lBullet->setPos(player->pos().rx(), player->pos().ry());
        rBullet->setPos(player->pos().rx() + CHARACTER_WIDTH/2, player->pos().ry());
        rBullet->setZValue(-1);
        lBullet ->setZValue(-1);
        scene->addItem(lBullet);
        scene->addItem(rBullet);
        bullets.append(lBullet);
        bullets.append(rBullet);
        Game::playSound(BULLET_SOUND);
    }
}

//Game over menu.
void Game::gameOver(){
    if(newHighScore())
        highScore = score->getScore();

    GuiElement* gameOver = new GuiElement();
    GuiElement* highScoreMessage = new GuiElement();


    gameOver->setText(QString("GAME OVER!"));
    gameOver->setPos(QPointF(scene->sceneRect().center()));
    //highScoreMessage->setText(QString("High Score " + QString::number(highScore)));
    highScoreMessage->setPos(scene->sceneRect().x()/2, scene->sceneRect().y()/2);
    scene->addItem(gameOver);
    scene->addItem(highScoreMessage);
}

//Play a sound effect.
void Game::playSound(QString path){
    sfx->play(path);
}
