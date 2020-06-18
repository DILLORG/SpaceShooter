#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSound>
#include <QFontDatabase>
#include "state.h"
#include "config.h"
class Game : public QGraphicsView{
private:
    QGraphicsScene* scene;
    QSound* sfx;

    Game();
    static Game* p_Instance;

public:
    Score* score;
    static Game* instance(){
        if(p_Instance==0){
            p_Instance = new Game();
        }
        return p_Instance;
    }
    void changeState(int stateNum);
    void playSound(QString path);


};
typedef Game TheGame;
#endif // GAMEWINDOW_H
