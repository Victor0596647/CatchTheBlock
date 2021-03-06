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

    private:
        CatchTheBlock *game;
        sf::RenderWindow* app;
        void initGame();
        void initWin();
};

#endif // GAME_H
