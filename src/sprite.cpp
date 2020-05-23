#include "sprite.h"
#include "config.h"
#include <exception>
#include <iostream>
#include "game.h"
AnimatedSprite::AnimatedSprite(const char* p, int f, int s, int e){
    spriteSheet = new QPixmap(p);
    frameSize = f;
    currentFrame = s;
    startFrame = s;
    endFrame = e;
    repeat = true;
}

QRectF AnimatedSprite::boundingRect() const{
    return QRectF(-10, -10, frameSize, frameSize);
}

void AnimatedSprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(-10, -10, *spriteSheet, currentFrame, 0, frameSize, frameSize);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void AnimatedSprite::changeAnimation(int s, int e){
    startFrame = s;
    endFrame = e;
}

void AnimatedSprite::nextFrame(){
    currentFrame += frameSize;
    if(currentFrame >= endFrame && repeat)
        currentFrame = startFrame;
    update(-10, -10, frameSize, frameSize);

}

Star::Star(){
    setPos(rand() % ( WINDOW_WIDTH - STAR_WIDTH) , 0);
    //This makes it appear that other objects are on top of the star field.
    setZValue(-1);
    setRect(0, 0, STAR_WIDTH, STAR_HEIGHT);
    setBrush(QColor(255, 255, 255));
}



Player::Player(const char* p, int f, int s, int e) : AnimatedSprite(p, f, s, e){
    setFlag(QGraphicsItem::ItemIsFocusable);

}

bool Player::isHit(){
    collisions = collidingItems();
    for(int i = 0; i < collisions.size(); i ++){
        if(typeid(*collisions[i]) == typeid(Enemy))
            return true;
    }
    return false;
}

Bullet::Bullet(){
    setRect(0, 0, BULLET_WIDTH, BULLET_HEIGHT);
    setBrush(QColor(34, 0, 255));
}


Enemy::Enemy(const char* p, int f, int s, int e) : AnimatedSprite(p, f, s, e){
    //Set random x position
    setPos(rand() % (WINDOW_WIDTH - 50), 0);
}

bool Enemy::isHit(){
    collisions = collidingItems();

    for(int i = 0; i < collisions.size(); i++){
        if(typeid (*collisions[i]) == typeid (Bullet))
            return true;
    }
    return false;
}

Explosion::Explosion(const char* p, int f, int s, int e) : AnimatedSprite(p, f, s, e){

}
