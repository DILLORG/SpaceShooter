#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QDir>
#include <memory>
#include "sprite.h"
#include "game.h"
#include <iostream>
#include <QDebug>

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    TheGame::instance()->show();
    return a.exec();
}
