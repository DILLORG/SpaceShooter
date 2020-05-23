#ifndef SPRITE_H
#define SPRITE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QSound>
#include <QObject>
#include <QList>
#include <stdlib.h>
class AnimatedSprite: public QGraphicsItem{
private:
    QPixmap* spriteSheet;
    int frameSize;
    int currentFrame;
    int startFrame;
    int endFrame;
    bool repeat;

public:
    AnimatedSprite(const char* p, int f, int s, int e);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void changeAnimation(int s, int e);
    void nextFrame();
    void setRepeat(bool value){repeat = value;};
    virtual bool isHit(){return false;};


};

class Star : public QGraphicsRectItem{
public:
    Star();
};

class Bullet : public QGraphicsRectItem{
public:
    Bullet();
};

class Player : public AnimatedSprite{
private:
    QList<QGraphicsItem*> collisions;
public:
    Player(const char* path, int f, int s, int e);
    bool isHit();
    ~Player(){}
};

class Enemy : public AnimatedSprite{
private:
    QList <QGraphicsItem*> collisions;

public:
    Enemy(const char* path, int f, int s, int e);
    bool isHit();
    ~Enemy(){};

};

class Explosion : public AnimatedSprite{
public:
    Explosion(const char* path, int f, int s, int e);
    void nextFrame();
    ~Explosion(){};
};

#endif // SPRITE_H
