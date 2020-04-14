#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QDir>
#include <memory>
#include "sprite.h"
#include <iostream>
#include <QDebug>
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    QGraphicsScene* scene = new QGraphicsScene();
    Sprite* rect = new Sprite();
    rect->setRect(0, 0, 50, 50);
    scene->addItem(rect);
    //Make rect focusable
    rect -> setFocus();
    qDebug() << QDir::currentPath();
    QGraphicsView* view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(640, 480);
    view->setWindowTitle("Space Shooter");
    scene->setSceneRect(0, 0, 640, 480);
    rect->setPos(view->width()/2, view->height() - rect->rect().height());

    return a.exec();
    
}
