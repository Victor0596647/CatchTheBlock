#include "mainMenu.h"
#include "CatchTheBlock.h"

CatchTheBlock gam;

mainMenu::mainMenu()
{
    initText();
}

mainMenu::~mainMenu()
{
    //dtor
}

void mainMenu::render(RenderTarget& target)
{
    if(!getGameStart() && !getSelecOption())
    {
        target.draw(mainTitle);
        target.draw(mainPlay);
        target.draw(mainOptions);
        target.draw(mainQuit);
    }else if(getSelecOption() == true)
    {
        target.draw(optTitle);
        target.draw(optVol);
        target.draw(optVolNum);
        target.draw(optThColor);
        target.draw(optTColor);
        target.draw(optPColor);
        target.draw(optBColor);
        target.draw(optExit);
    }
}

void mainMenu::renderPause(RenderTarget& target)
{
    target.draw(pausTitle);
    target.draw(pausResume);
    target.draw(pausBackMenu);
    target.draw(pausQuit);
}

void mainMenu::update(Window& target)
{
    if(getGamePause() == true){
        if((Mouse::getPosition(target).x >= pausResume.getPosition().x && Mouse::getPosition(target).x <= pausResume.getPosition().x + 85
                && Mouse::getPosition(target).y >= pausResume.getPosition().y && Mouse::getPosition(target).y <= 290))
        {
            pausResume.setFillColor(getHoverColor());
            if(Mouse::isButtonPressed(Mouse::Button::Left))
            {
                setGamePause(false);
            }
        }
        else
        {
            pausResume.setFillColor(globalTextColor);
        }
    }
    if(getSelecOption() == false)
    {
        if(ctrlSelec.Axis::PovX > 6)
        {
            std::cout << ctrlSelec.Axis::PovX << std::endl;
        }
        if((Mouse::getPosition(target).x >= mainPlay.getPosition().x && Mouse::getPosition(target).x <= mainPlay.getPosition().x + 85
                && Mouse::getPosition(target).y >= mainPlay.getPosition().y && Mouse::getPosition(target).y <= 290))
        {
            mainPlay.setFillColor(getHoverColor());
            if(Mouse::isButtonPressed(Mouse::Button::Left))
            {
                gameStart = true;
            }
        }
        else if(Mouse::getPosition(target).x >= mainOptions.getPosition().x && Mouse::getPosition(target).x <= mainOptions.getPosition().x + 155
                && Mouse::getPosition(target).y >= mainOptions.getPosition().y && Mouse::getPosition(target).y <= 340)
        {
            mainOptions.setFillColor(getHoverColor());
            if(Mouse::isButtonPressed(Mouse::Button::Left))
            {
                setSelecOption(true);
            }
        }
        else if(Mouse::getPosition(target).x >= mainQuit.getPosition().x && Mouse::getPosition(target).x <= mainQuit.getPosition().x + 85
                && Mouse::getPosition(target).y >= mainQuit.getPosition().y && Mouse::getPosition(target).y <= 390)
        {
            mainQuit.setFillColor(hoverColor);
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
    else if(getSelecOption())
    {
        if(Mouse::getPosition(target).x >= optExit.getPosition().x && Mouse::getPosition(target).x <= optExit.getPosition().x + 85
                && Mouse::getPosition(target).y >= optExit.getPosition().y && Mouse::getPosition(target).y <= 560)
        {
            optExit.setFillColor(getHoverColor());
            if(Mouse::isButtonPressed(Mouse::Button::Left))
            {
                setSelecOption(false);
            }
        }
        else if(Mouse::getPosition(target).x >= optVol.getPosition().x && Mouse::getPosition(target).x <= optVol.getPosition().x + 240
                && Mouse::getPosition(target).y >= optVol.getPosition().y && Mouse::getPosition(target).y <= 290)
        {
            optVolNum.setFillColor(getHoverColor());
            if(Mouse::isButtonPressed(Mouse::Button::Left))
            {
                vol++;
                if(vol > 100)
                {
                    vol = 0;
                }
            }
            optVolNum.setString(std::to_string(vol));
        }
        else
        {
            optExit.setFillColor(globalTextColor);
            optVolNum.setFillColor(globalHeadingColor);
        }
    }
}

void mainMenu::initText()
{
    setTextColor(hoverColor,"green");
    setTextColor(globalTextColor,"white");
    setTextColor(globalHeadingColor,"red");

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

    //Volume
    optVol.setFont(pix);
    optVol.setString("Volume:");
    optVol.setCharacterSize(40);
    optVol.setPosition(0.f, 250.f);
    optVol.setFillColor(globalTextColor);

    //Volume Set Sound
    optVolNum.setFont(pix);
    optVolNum.setString(std::to_string(vol));
    optVolNum.setCharacterSize(40);
    optVolNum.setPosition(optVol.getPosition().x + 170, optVol.getPosition().y);
    optVolNum.setFillColor(globalHeadingColor);

    //Text Heading Color
    optThColor.setFont(pix);
    optThColor.setString("Change Text Heading Color:");
    optThColor.setCharacterSize(40);
    optThColor.setPosition(0.f, 300.f);
    optThColor.setFillColor(globalTextColor);

    //Change Text Color
    optTColor.setFont(pix);
    optTColor.setString("Change Text Color:");
    optTColor.setCharacterSize(40);
    optTColor.setPosition(0.f, 350.f);
    optTColor.setFillColor(globalTextColor);

    //Player Color
    optPColor.setFont(pix);
    optPColor.setString("Change Player Color:");
    optPColor.setCharacterSize(40);
    optPColor.setPosition(0.f, 400.f);
    optPColor.setFillColor(globalTextColor);

    //Block Color
    optBColor.setFont(pix);
    optBColor.setString("Change Block Color:");
    optBColor.setCharacterSize(40);
    optBColor.setPosition(0.f, 450.f);
    optBColor.setFillColor(globalTextColor);

    //Exit Option
    optExit.setFont(pix);
    optExit.setString("Exit");
    optExit.setCharacterSize(40);
    optExit.setPosition(0.f, 520.f);
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

    //Quit Game
    pausQuit.setFont(pix);
    pausQuit.setString("Quit Game");
    pausQuit.setCharacterSize(40.f);
    pausQuit.setPosition(0.f, 350.f);
    pausQuit.setFillColor(globalTextColor);
    /*Pause Menu*End*/
}
