#include "sprite.h"
#include "config.h"
#include <exception>
#include <iostream>
#include "game.h"

Star::Star(){
    QTimer* timer = new QTimer();
    int randPos = rand() % (WINDOW_WIDTH - STAR_WIDTH);
    this->setPos(randPos, 0);
    //This makes it appear that other objects are on top of the star field.
    this->setZValue(-1);
    this->setRect(0, 0, STAR_WIDTH, STAR_HEIGHT);
    this->setBrush(QColor(255, 255, 255));

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(STAR_SPEED);
}

void Star::move(){
    this->setPos(x(), y() + 5);

    if(pos().y() + rect().height() > WINDOW_HEIGHT){
        this->scene()->removeItem(this);
        delete this;
    }
}

Player::Player(){
    setFlag(QGraphicsItem::ItemIsFocusable);
    setPixmap(QPixmap(":/assets/ship_sprite.png"));
}

Bullet::Bullet(){
    QTimer* timer = new QTimer();

    setPixmap(QPixmap(":/assets/bullet_sprite.png"));
    this->connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    //Move bullet depedent on speed.
    timer->start(BULLET_SPEED);
}

void Bullet::move(){

    collisions = collidingItems();
    //Delete enemys that colide with bullets
    for(int i=0; i< collisions.size(); i++){
        if(typeid (*(collisions[i]))== typeid (Enemy)){

            TheGame::instance()->playSound(":/assets/blow_up.wav");
            scene()->removeItem(collisions[i]);
            scene()->removeItem(this);
            delete  collisions[i];
            delete this;
            TheGame::instance()->score->increaseScore();
            return;
        }
    }
    setPos(x(), y() - 10);
    //Remove and delete items that clear our screen.
    if((pos().y() < 0)){
        scene()->removeItem(this);
        delete this;
    }

}

Enemy::Enemy(){

    //Set random x position
    int randPos = rand() % (WINDOW_WIDTH - 50);
    setPos(randPos, 0);
    setPixmap(QPixmap(":/assets/enemy_sprite.png"));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(ENEMY_SPEED);

}

void Enemy::move(){
    setPos(x(), y() + 5);
    collisions=collidingItems();
    for(int i=0; i< collisions.size(); i++){
        if(typeid (*(collisions[i])) == typeid (Player)){
            scene()->removeItem(collisions[i]);
            scene()->removeItem(this);
            delete  collisions[i];
            delete this;
            TheGame::instance()->gameOver();
            return;
        }
    }
    if(pos().y() > WINDOW_HEIGHT){
        scene()->removeItem(this);
        delete this;
    }
}
