#include "game.h"
Game* Game::p_Instance  = 0;

Game::Game(){
    QFontDatabase::addApplicationFont(FONT);
    scene = new MenuState();

    this->setScene(scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    this->setWindowTitle(GAME_NAME);
}

//Change windows scene depending on passed state.
void Game::changeState(int stateNum){
    scene->destroyed();
    switch(stateNum){
        case 0:
            scene = new PlayState();
        break;
        case 1:
            scene = new GameOverState();
         break;
        case 2:
          scene = new MenuState();
        break;
    }
    this->setScene(scene);

}
//Play a sound effect.
void Game::playSound(QString path){
    sfx->play(path);
}
