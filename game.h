#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

using namespace sf;

class game
{
    public:
        sf::RenderWindow* app;
        game();
        virtual ~game();

    private:
        void initWin();
        void initMenu();
        void initGame();
};

#endif // GAME_H
