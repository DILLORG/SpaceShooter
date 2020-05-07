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
class Sprite : public QObject{
Q_OBJECT
public:
    Sprite(){};
};

class Star : public Sprite, public QGraphicsRectItem{
Q_OBJECT
public:
    Star();
public slots:
    void move();
};

class Player : public Sprite, public QGraphicsPixmapItem{
Q_OBJECT
public:
    Player();
};

class Bullet : public Sprite, public QGraphicsPixmapItem{
Q_OBJECT
private:
    QList<QGraphicsItem*> collisions;
public:
    Bullet();


public slots:
    void move();

};

class Enemy : public Sprite, public QGraphicsPixmapItem{
    Q_OBJECT
private:

    QTimer* timer;
    QList <QGraphicsItem*> collisions;

public:
    Enemy();

public slots:
    void move();


};
#endif // SPRITE_H
