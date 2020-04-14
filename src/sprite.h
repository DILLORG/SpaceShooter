#ifndef SPRITE_H
#define SPRITE_H
#include <QGraphicsRectItem>
#include <QObject>
class Sprite : public QGraphicsRectItem{
public:
    void keyPressEvent(QKeyEvent* event);
    Sprite();
};

class Bullet : public QObject, public Sprite{
Q_OBJECT
public:
    Bullet();
public slots:
    void move();

};

#endif // SPRITE_H
