#include "mainMenu.h"
#include "CatchTheBlock.h"

CatchTheBlock gam;

mainMenu::mainMenu()
{
    initText();
}

void mainMenu::render(RenderTarget& target)
{
    if(!getGameStart() && !getSelecOption())
    {
        target.draw(mainTitle);
        target.draw(mainPlay);
        target.draw(mainOptions);
        target.draw(mainQuit);
    }
    if(getSelecOption())
    {
        target.draw(optTitle);
        target.draw(optPColor);
        target.draw(optPColorSel);
        target.draw(optBColor);
        target.draw(optBColorSel);

        target.draw(optExit);
    }
    if(getGamePause() && getGameStart())
    {
        target.draw(pausTitle);
        target.draw(pausResume);
        target.draw(pausBackMenu);
    }
}

void mainMenu::update(Window& target)
{
    //Main Menu Function
    if(!getGameStart() && !getSelecOption() && !getGamePause())
    {
        if((Mouse::getPosition(target).x >= mainPlay.getPosition().x && Mouse::getPosition(target).x <= mainPlay.getPosition().x + 85
                && Mouse::getPosition(target).y >= mainPlay.getPosition().y && Mouse::getPosition(target).y <= mainPlay.getPosition().y + mainPlay.getCharacterSize()))
        {
            mainPlay.setFillColor(getHoverColor());
            if(Mouse::isButtonPressed(Mouse::Button::Left))
            {
                setGameStart(true);
            }
        }
        else if(Mouse::getPosition(target).x >= mainOptions.getPosition().x && Mouse::getPosition(target).x <= mainOptions.getPosition().x + 155
                && Mouse::getPosition(target).y >= mainOptions.getPosition().y && Mouse::getPosition(target).y <= mainOptions.getPosition().y + mainOptions.getCharacterSize())
        {
            mainOptions.setFillColor(getHoverColor());
            if(Mouse::isButtonPressed(Mouse::Button::Left))
            {
                setSelecOption(true);
            }
        }
        else if(Mouse::getPosition(target).x >= mainQuit.getPosition().x && Mouse::getPosition(target).x <= mainQuit.getPosition().x + 85
                && Mouse::getPosition(target).y >= mainQuit.getPosition().y && Mouse::getPosition(target).y <= mainQuit.getPosition().y + mainQuit.getCharacterSize())
        {
            mainQuit.setFillColor(getHoverColor());
            if(Mouse::isButtonPressed(Mouse::Button::Left))
            {
                quit = true;
            }
        }
        else
        {
            mainPlay.setFillColor(globalTextColor);
            mainOptions.setFillColor(globalTextColor);
            mainQuit.setFillColor(globalTextColor);
        }
    }

    //Options Function
    if(getSelecOption() && !getGameStart() && !getGamePause())
    {
        if(Mouse::getPosition(target).x >= optExit.getPosition().x && Mouse::getPosition(target).x <= optExit.getPosition().x + 85
                && Mouse::getPosition(target).y >= optExit.getPosition().y && Mouse::getPosition(target).y <= optExit.getPosition().y + optExit.getCharacterSize())
        {
            optExit.setFillColor(hoverColor);
            if(Mouse::isButtonPressed(Mouse::Button::Left))
            {
                setSelecOption(false);
            }
        }
        else
        {
            optExit.setFillColor(globalTextColor);
        }
    }

    //Pause Menu Funtion
    if(getGamePause() && getGameStart())
    {
        if((Mouse::getPosition(target).x >= pausResume.getPosition().x && Mouse::getPosition(target).x <= pausResume.getPosition().x + 130
                && Mouse::getPosition(target).y >= pausResume.getPosition().y && Mouse::getPosition(target).y <= pausResume.getPosition().y + pausResume.getCharacterSize()))
        {
            pausResume.setFillColor(getHoverColor());
            if(Mouse::isButtonPressed(Mouse::Button::Left))
            {
                setGamePause(false);
            }
        }
        else if(Mouse::getPosition(target).x >= pausBackMenu.getPosition().x && Mouse::getPosition(target).x <= pausBackMenu.getPosition().x + 305
                && Mouse::getPosition(target).y >= pausBackMenu.getPosition().y && Mouse::getPosition(target).y <= pausBackMenu.getPosition().y + pausResume.getCharacterSize())
        {
            pausBackMenu.setFillColor(getHoverColor());
            if(Mouse::isButtonPressed(Mouse::Button::Left))
            {
                Mouse::setPosition(Vector2i( 100.f, 100.f), target);
                Mouse::setPosition(Vector2i( sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));

                setGamePause(false);
                setGameStart(false);
            }
        }
        else
        {
            pausResume.setFillColor(globalTextColor);
            pausBackMenu.setFillColor(globalTextColor);
        }
    }
}

void mainMenu::initText()
{
    setColor(playerColor, "red");
    setColor(blockColor, "white");
    setColor(hoverColor, "green");
    setColor(globalTextColor, "white");
    setColor(globalHeadingColor, "red");

    pix.loadFromFile("res/consola.ttf");

    /*Main Menu*/

    //Title Screen
    mainTitle.setFont(pix);
    mainTitle.setCharacterSize(80);
    mainTitle.setPosition(0.f, 100.f);
    mainTitle.setFillColor(globalHeadingColor);
    mainTitle.setString("Catch The Block");

    //Play
    mainPlay.setFont(pix);
    mainPlay.setCharacterSize(40);
    mainPlay.setPosition(0.f, 250.f);
    mainPlay.setFillColor(globalTextColor);
    mainPlay.setString("Play");

    //Options
    mainOptions.setFont(pix);
    mainOptions.setCharacterSize(40);
    mainOptions.setPosition(0.f, 300.f);
    mainOptions.setFillColor(globalTextColor);
    mainOptions.setString("Options");

    //Quit
    mainQuit.setFont(pix);
    mainQuit.setCharacterSize(40);
    mainQuit.setPosition(0.f, 350.f);
    mainQuit.setFillColor(globalTextColor);
    mainQuit.setString("Quit");


    /*Options*/
    optTitle.setFont(pix);
    optTitle.setString("Options");
    optTitle.setCharacterSize(80);
    optTitle.setPosition(0.f, 100.f);
    optTitle.setFillColor(globalHeadingColor);

    //Player Color
    optPColor.setFont(pix);
    optPColor.setString("Change Player Color:");
    optPColor.setCharacterSize(40);
    optPColor.setPosition(0.f, 250.f);
    optPColor.setFillColor(globalTextColor);

    optPColorSel.setFont(pix);
    optPColorSel.setString("Player");
    optPColorSel.setCharacterSize(40);
    optPColorSel.setPosition(440.f, 250.f);
    optPColorSel.setFillColor(getPlayerColor());

    //Block Color
    optBColor.setFont(pix);
    optBColor.setString("Change Block Color:");
    optBColor.setCharacterSize(40);
    optBColor.setPosition(0.f, 300.f);
    optBColor.setFillColor(globalTextColor);

    optBColorSel.setFont(pix);
    optBColorSel.setString("Block");
    optBColorSel.setCharacterSize(40);
    optBColorSel.setPosition(420.f, 300.f);
    optBColorSel.setFillColor(getBlockColor());

    //Exit Option
    optExit.setFont(pix);
    optExit.setString("Exit");
    optExit.setCharacterSize(40);
    optExit.setPosition(0.f, 400.f);
    optExit.setFillColor(globalTextColor);
    /*Option*End*/

    /*Pause Menu*/
    //Paused Title
    pausTitle.setFont(pix);
    pausTitle.setString("Paused");
    pausTitle.setCharacterSize(80.f);
    pausTitle.setPosition(0.f, 100.f);
    pausTitle.setFillColor(globalHeadingColor);

    //Resume
    pausResume.setFont(pix);
    pausResume.setString("Resume");
    pausResume.setCharacterSize(40.f);
    pausResume.setPosition(0.f, 250.f);
    pausResume.setFillColor(globalTextColor);

    //Return to Menu
    pausBackMenu.setFont(pix);
    pausBackMenu.setString("Return To Menu");
    pausBackMenu.setCharacterSize(40.f);
    pausBackMenu.setPosition(0.f, 300.f);
    pausBackMenu.setFillColor(globalTextColor);

    /*Pause Menu*End*/
}
