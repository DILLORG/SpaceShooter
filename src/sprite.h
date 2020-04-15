#ifndef SPRITE_H
#define SPRITE_H
#include <QGraphicsRectItem>
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QSound>
#include <QObject>
class Sprite : public QGraphicsRectItem{
public:
//    void keyPressEvent(QKeyEvent* event);
    Sprite();
};

class Player : public QObject, public Sprite{
private:
    int score;
public:
    void keyPressEvent(QKeyEvent* event);
    void addToScore(int value);
    int getScore(){return this -> score;};
    Player();
};

class Bullet : public QObject, public Sprite{
Q_OBJECT
public:
    Bullet();
public slots:
    void move();

};

#endif // SPRITE_H
