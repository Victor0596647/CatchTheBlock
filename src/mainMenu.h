#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class mainMenu
{
public:
    void render(RenderTarget& target);
    void renderPause(RenderTarget& target);
    void update(Window& target);
    void setGameStart(bool Astart)
    {
        gameStart = Astart;
    }
    void setQuit(bool Aquit)
    {
        quit = Aquit;
    }
    void setSelecOption(bool Aoption)
    {
        option = Aoption;
    }
    void setGamePause(bool Apause)
    {
        setPause = Apause;
    }
    void setTextColor(Color &text,std::string color)
    {
        if(color == "red")
        {
            text = Color::Red;
        }
        else if(color == "green")
        {
            text = Color::Green;
        }
        else if(color == "blue")
        {
            text = Color::Blue;
        }
        else if(color == "yellow")
        {
            text = Color::Yellow;
        }
        else if(color == "white")
        {
            text = Color::White;
        }
    }
    void setGameVolume();
    bool getGameStart()
    {
        return gameStart;
    }
    bool getSelecOption()
    {
        return option;
    }
    bool getQuit()
    {
        return quit;
    }
    bool getGamePause()
    {
        return setPause;
    }
    Color getTextColor()
    {
        return globalTextColor;
    }
    Color getHeadingColor()
    {
        return globalHeadingColor;
    }
    Color getHoverColor()
    {
        return hoverColor;
    }
    mainMenu();
    virtual ~mainMenu();

private:
    //Color
    Color hoverColor;
    Color globalTextColor;
    Color globalHeadingColor;
    Color ColorR;
    Color ColorY;
    Color ColorG;
    Color ColorB;
    Color ColorW;
    Joystick ctrlSelec;

    void initText();

    int vol = 100;
    int selection;
    bool option;
    bool quit;
    bool gameStart;
    bool setPause = 0;

    Font pix;

    //Main Menu
    Text mainTitle;
    Text mainPlay;
    Text mainOptions;
    Text mainQuit;

    //Options
    Text optExit;
    Text optTitle;
    Text optVol;
    Text optVolNum;
    Text optThColor;
    Text optTColor;
    Text optPColor;
    Text optBColor;

    //Pause Menu
    Text pausResume;
    Text pausBackMenu;
    Text pausTitle;
    Text pausQuit;

};

#endif // MAINMENU_H
