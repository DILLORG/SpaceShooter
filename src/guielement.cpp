#include "guielement.h"

TextElement::TextElement(const char* t){

    font = new QFont("Thintel", SMALL_FONT_SIZE);
    setDefaultTextColor(QColor(255, 255, 255));
    setFont(*font);
    setPlainText(t);
}


Button::Button(const char* t){
     font = new QFont("Thintel", FONT_SIZE);
     this->setFont(*font);
     this->setText(t);
     this->setStyleSheet("background-color: rgba(0, 0, 0, 0); color:rgba(0, 0, 0, 255);");
     this->setFlat(true);
}

Score::Score(const char* t) : TextElement(t){
   score = 0;
}

void Score::increaseScore(){
    score++;
    this->setPlainText(QString("Score:" + QString::number(score)));
}
