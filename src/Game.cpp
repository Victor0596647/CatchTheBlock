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
    this->app = new RenderWindow(VideoMode(1280, 720), "Catch The Block", Style::Close);
    this->app->setKeyRepeatEnabled(false);
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(this->app->isOpen())
    {
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            updatePollEvents();
            update();
        }
        timeSinceLastUpdate += clock.restart();
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
            //Pausing game
            if(Keyboard::isKeyPressed(Keyboard::Key::P) && !this->game->menu.getGamePause() && !this->game->getGameWin() && !this->game->getGameLose() && !this->game->menu.getSelecOption() && this->game->menu.getGameStart())
            {
                this->game->menu.setGamePause(true);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Key::P) && this->game->menu.getGamePause() == true)
            {
                this->game->menu.setGamePause(false);
            }
        }
    }
    update();
}
