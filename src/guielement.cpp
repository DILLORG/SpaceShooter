#include "guielement.h"
GuiElement::GuiElement(){
    font = new QFont("times", FONT_SIZE);
    setDefaultTextColor(QColor(255, 255, 255));
    setFont(*font);
}

void GuiElement::setText(QString text){
    setPlainText(text);
}

Score::Score(){
   score = 0;
   GuiElement::setText(QString("Score:" + QString::number(score)));
}

void Score::increaseScore(){
    score++;
    GuiElement::setText(QString("Score:" + QString::number(score)));
}


