#ifndef GAME_H
#define GAME_H
#include "CatchTheBlock.h"


class Game
{
public:
    Game();
    virtual ~Game();
    void run();
    void update();
    void render();
    void updatePollEvents();
    sf::RenderWindow* app;

private:
    const float frameLimit = 144.f;
    CatchTheBlock *game;
    const sf::Time TimePerFrame = sf::seconds(1.f/frameLimit);
    void initGame();
    void initWin();
};

#endif // GAME_H
