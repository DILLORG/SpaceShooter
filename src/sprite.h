#ifndef SPRITE_H
#define SPRITE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>
#include <QList>


class Sprite : public QGraphicsRectItem{
public:
    Sprite(){}
    virtual void updatePos() = 0;
    ~Sprite(){}
};

class AnimatedSprite: public QObject, public QGraphicsItem{
Q_OBJECT
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
    void draw();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void changeAnimation(int s, int e);
    void setRepeat(bool value){repeat = value;}
    virtual bool isHit(){return false;}
    virtual void updatePos(){};
};

class Star :public Sprite{

public:
    Star();
    void updatePos() override;
    ~Star(){};
};

class Bullet : public Sprite{

public:
    Bullet();
    void updatePos() override;
    ~Bullet(){};
};

class Player : public AnimatedSprite{
Q_OBJECT
private:
    QList<QGraphicsItem*> collisions;
public:
    Player(const char* path, int f, int s, int e);
    bool isHit() override;
    ~Player(){}
};

class Enemy : public AnimatedSprite{
Q_OBJECT
private:
    QList <QGraphicsItem*> collisions;

public:
    Enemy(const char* path, int f, int s, int e);
    bool isHit() override;
    void updatePos() override;
    ~Enemy(){};

};

class Explosion : public AnimatedSprite{

public:
    Explosion(const char* path, int f, int s, int e);
    void updatePos() override;
    ~Explosion(){};
};

#endif // SPRITE_H
