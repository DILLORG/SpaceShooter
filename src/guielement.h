#ifndef GUIELEMENT_H
#define GUIELEMENT_H
#include <QGraphicsTextItem>
#include <QPushButton>
#include <QIcon>
#include <QFont>
#include "config.h"

class TextElement: public QGraphicsTextItem{
private:
    int score;
    QFont* font;

public:
    TextElement(const char* t);
    ~TextElement(){}
};

class Button : public QPushButton{
private:
   QFont* font;
public:
    Button(const char* t);
    ~Button(){}
};

class Score: public TextElement{
private:
    int score;
public:
    Score(const char* t);
    int getScore(){return this->score;};
    void increaseScore();
    ~Score(){}
};
#endif // GUIELEMENT_H
