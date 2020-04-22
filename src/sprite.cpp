#include "sprite.h"
#include "config.h"
#include <exception>
#include <iostream>
Sprite::Sprite(){

}
Player::Player(){
    setFlag(QGraphicsItem::ItemIsFocusable);
    try{
        spriteSheet = new QPixmap(":assets/ShipSpriteSheet.png");
    }catch(std::exception& e){
        std::cerr << "FILE NOT FOUND " << e.what() << std::endl;
    }

}

void Player::keyPressEvent(QKeyEvent *event){
     //Move ship based on direction play is pressing on controls.
    if(event->key() == Qt::Key_A && pos().x() > 0){
        setPos(x() - SHIP_SPEED_FACTOR, y());
    }else if(event->key() == Qt::Key_D && pos().x() +100 < 800){
        setPos(x()+ SHIP_SPEED_FACTOR, y());
    }else if(event->key() == Qt::Key_W){
        setPos(x(), y() - SHIP_SPEED_FACTOR);
    }else if(event->key() == Qt::Key_S){
        setPos(x(), y() + SHIP_SPEED_FACTOR);

    //Fire bullet.
    }else if(event->key() == Qt::Key_Space){
        Bullet* bullet = new Bullet();
        bullet ->setPos(x() + rect().width()/2, y());
        scene()->addItem(bullet);
        try{
            sfx->play(":/assets/bullet_sound.wav");
        }catch(std::exception& e){
            std::cerr << "FILE NOT FOUND: " << e.what() << std::endl;
        }

     }
}

void Player::addToScore(int value){
    score += value;
}
Bullet::Bullet(){
    QTimer* timer = new QTimer();
    setBrush(QColor(255, 28, 154));
    setRect(0, 0, BULLET_WIDTH, BULLET_HEIGHT);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    //Move bullet depedent on speed.
    timer->start(BULLET_SPEED);
}

void Bullet::move(){
    setPos(x(), y() - 10);

    //Remove and delete items that clear our screen.
    if((pos().y() + rect().height()) < 0){
        scene()->removeItem(this);
        delete this;
    }
}
