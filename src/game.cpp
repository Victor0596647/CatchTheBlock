#include "game.h"
#include "CatchTheBlock.h"

CatchTheBlock *game1;

game::game()
{
    initWin();
    initMenu();
}

game::~game()
{
    //dtor
}

void game::initWin(){
    this->app = new RenderWindow(VideoMode(1280,720),"Catch The Block", Style::Titlebar | Style::Close);
    this->app->setVerticalSyncEnabled(false);
    this->app->setKeyRepeatEnabled(false);
}


