#include "sprite.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QSound>
#include "config.h"
Sprite::Sprite(){
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void Sprite::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_A && pos().x() > 0){
        setPos(x() - SHIP_SPEED_FACTOR, y());
    }else if(event->key() == Qt::Key_D && pos().x() +100 < 800){
        setPos(x()+ SHIP_SPEED_FACTOR, y());
    }else if(event->key() == Qt::Key_W){
        setPos(x(), y() - SHIP_SPEED_FACTOR);
    }else if(event->key() == Qt::Key_S){
        setPos(x(), y() + SHIP_SPEED_FACTOR);
    }else if(event-> key() == Qt::Key_Space){
       //Create Bullet.
        Bullet* bullet = new Bullet();
        bullet ->setPos(x() + rect().width()/2, y());
        scene() -> addItem(bullet);
        QSound::play(":/assets/bullet_sound.wav");
    }
}

Bullet::Bullet(){
    QTimer* timer = new QTimer();
    setRect(0, 0, 10, 50);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move(){
    setPos(x(), y() - 10);

    //Remove and delete items that clear our screen.
    if((pos().y() + rect().height()) < 0){
        scene()->removeItem(this);
        delete this;
    }
}
