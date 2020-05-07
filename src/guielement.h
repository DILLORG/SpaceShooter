#ifndef GUIELEMENT_H
#define GUIELEMENT_H
#include <QGraphicsTextItem>
#include <QFont>
#include "config.h"

class GuiElement: public QGraphicsTextItem{
private:
    int score;
    QFont* font;

public:
    GuiElement();
    void setText(QString text);

};

class Score: public GuiElement{
private:
    int score;
public:
    Score();
    int getScore(){return this->score;};
    void increaseScore();
};
#endif // GUIELEMENT_H
