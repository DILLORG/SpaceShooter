#include "state.h"
#include "config.h"
#include "game.h"
State::State(){

}

PlayState::PlayState(){
    player = new Player(PLAYER_SPRITE, 50, 0, 150);
    score = new Score("Score:");
    starSpawnTimer = new QTimer;
    enemySpawnTimer = new QTimer;
    updateTimer = new QTimer;
    drawTimer = new QTimer;
    collisionTimer = new QTimer;
    this->setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    this->setBackgroundBrush(QBrush(QColor(0, 0, 0)));
    player->setFocus();
    player->setPos(QPointF(this->sceneRect().center()));
    this->addItem(player);
    this->addItem(score);
    connect(starSpawnTimer, SIGNAL(timeout()), this, SLOT(drawStarField()));
    starSpawnTimer->start(STAR_SPAWN_FREQUENCY);

    connect(enemySpawnTimer, SIGNAL(timeout()), this, SLOT(spawn()));
    enemySpawnTimer->start(ENEMY_SPAWN_FREQUENCY);

    connect(updateTimer, SIGNAL(timeout()), this, SLOT(update()));
    updateTimer->start(UPDATE_SPEED);

    connect(drawTimer, SIGNAL(timeout()), this, SLOT(draw()));
    drawTimer->start(ANIMATION_SPEED);

    connect(collisionTimer, SIGNAL(timeout()), this, SLOT(checkCollisions()));
    collisionTimer->start(UPDATE_SPEED);

    PlayState::initStarField();
}

void PlayState::update(){
    for(int i=0; i < explosions.size(); i++){
       explosions[i] -> updatePos();
       if(explosions[i]->pos().y() > WINDOW_HEIGHT){
        this->removeItem(explosions[i]);
        explosions.removeAt(i);
      }
    }
    for(int i=0; i < enemies.size(); i++){
         enemies[i] -> updatePos();
        if(enemies[i]->pos().y()> WINDOW_HEIGHT){
            this->removeItem(enemies[i]);
            enemies.removeAt(i);
         }
    }

    for(int i = 0; i < bullets.size(); i++){
        bullets[i]->updatePos();
        if(bullets[i]->pos().y() < 0){
            this->removeItem(bullets[i]);
            bullets.removeAt(i);
        }
    }

    for(int i =0; i < stars.size(); i++){
        stars[i]->updatePos();
        if(stars[i]-> pos().y()> WINDOW_HEIGHT){
            this->removeItem(stars[i]);
            stars.removeAt(i);
        }
    }

}

void PlayState::draw(){
    for(auto& enemy : enemies)
        enemy->draw();

    for(auto& explosion : explosions)
        explosion->draw();

    player->draw();
}
void PlayState::spawn(){
    Enemy* enemy = new Enemy(ENEMY_SPRITE, 50, 0,  150);
    this->addItem(enemy);
    enemies.append(enemy);
}

void PlayState::checkCollisions(){
    for(int i =0; i < enemies.size(); i++){
        if(enemies[i]->isHit()){
            TheGame::instance()->playSound(BLOW_UP);
            this->removeItem(enemies[i]);
            Explosion* explosion = new Explosion(EXPLOSION_SPRITE, 50, 0, 150);
            explosion->setPos(enemies[i]->pos());
            explosions.append(explosion);
            enemies.removeAt(i);

            score->increaseScore();
            this->addItem(explosion);

        }
    }


    if(player->isHit()){
        TheGame::instance()->playSound(BLOW_UP);
        this->removeItem(player);
        Explosion* explosion = new Explosion(EXPLOSION_SPRITE, 50, 0, 150);
        explosion->setPos(player->pos());
        this->addItem(explosion);
        explosions.append(explosion);
        TheGame::instance()->changeState(1);
    }
}

void PlayState::initStarField(){
    for(int i=0; i< 200; i++){
        Star* star = new Star();
        star->setY(rand() % WINDOW_HEIGHT);
        star->setX(rand()% WINDOW_WIDTH);
        this->addItem(star);
        stars.append(star);
    }
}

void PlayState::drawStarField(){
    for(int i =0; i < NUM_STARS; i++){
        Star* star = new Star();
        this->addItem(star);
        stars.append(star);
    }
}

void PlayState::keyPressEvent(QKeyEvent *event){
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
       rBullet->setPos(player->pos().rx() + 50/2, player->pos().ry());
       rBullet->setZValue(-1);
       lBullet ->setZValue(-1);
       this->addItem(lBullet);
       this->addItem(rBullet);
       bullets.append(lBullet);
       bullets.append(rBullet);
       TheGame::instance()->playSound(BULLET_SOUND);
   }
}


GameOverState::GameOverState(){
    replayButton = new Button("Replay?");
    connect(replayButton, SIGNAL(pressed()), this, SLOT(replayClick()));
    //this->setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    //this->addItem(gameOverLbl);
    this->addWidget(replayButton);
    this->setSceneRect(replayButton->rect());
    this->setBackgroundBrush(QBrush(QColor(255, 255, 255)));

}

void GameOverState::replayClick(){
    TheGame::instance()->changeState(0);
}

MenuState::MenuState(){
  playButton = new Button("Play");
  connect(playButton, SIGNAL(pressed()), this, SLOT(playClick()));
  this->addWidget(playButton);
  this->setSceneRect(playButton->rect());
  this->setBackgroundBrush(QBrush(QColor(255, 255, 255)));
}

void MenuState::playClick(){
  TheGame::instance()->changeState(0);
}
