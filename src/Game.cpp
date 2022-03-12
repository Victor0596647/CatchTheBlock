#include "Game.h"

using namespace sf;

Game::Game()
{
    initWin();
    initGame();
    run();
}

Game::~Game()
{
    //dtor
}

void Game::initGame()
{
    this->game = new CatchTheBlock;
}

void Game::initWin()
{
    this->app = new RenderWindow (VideoMode(1280, 720), "Catch The Block", Style::Close);
    this->app->setKeyRepeatEnabled(false);
}

void Game::run()
{
    while(this->app->isOpen())
    {
        updatePollEvents();
        render();
    }
}

void Game::update()
{
    this->game->update(*app);
}

void Game::render()
{
    this->app->clear();
    this->game->render(*app);
    this->app->display();
}

void Game::updatePollEvents()
{
    Event event;
    while(this->app->pollEvent(event))
    {
        switch (event.type)
        {
        case Event::Closed:
            this->app->close();
            break;
        case Event::KeyPressed:
            if(Keyboard::isKeyPressed(Keyboard::Key::Escape))
            {
                this->app->close();
            }
            if(Keyboard::isKeyPressed(Keyboard::Key::P) && !game->getGameLose() && !game->getGameWin())
            {
                if(game->menu.getGamePause() == false)
                {
                    game->menu.setGamePause(true);
                }
                else if(game->menu.getGamePause() == true)
                {
                    game->menu.setGamePause(false);
                }
            }
            break;
        }
    }
    update();
}
