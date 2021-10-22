#ifndef MAINMENU_H
#define MAINMENU_H
#include "CatchTheBlock.h"

using namespace sf;

class mainMenu
{
    public:

        void render(sf::RenderTarget &target);
        void update();
        void setRenderTarget(sf::RenderTarget &target);
        mainMenu();
        virtual ~mainMenu();

    private:
        void initText();
        Font pix;
        Text mainTitle;
        Text mainPlay;
        Text mainOptions;
        Text mainQuit;
};

#endif // MAINMENU_H
