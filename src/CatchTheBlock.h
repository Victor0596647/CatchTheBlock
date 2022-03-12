#ifndef CATCHTHEBLOCK_H
#define CATCHTHEBLOCK_H
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "mainMenu.h"

using namespace sf;

class CatchTheBlock
{
public:
    mainMenu menu;
    CatchTheBlock();
    virtual ~CatchTheBlock();
    void render(RenderTarget& target);
    void update(Window& target);
    void setGameWin(bool Awin)
    {
        win = Awin;
    }
    void setGameLose(bool Alose)
    {
        Lost = Alose;
    }
    bool getGameWin()
    {
        return win;
    }
    bool getGameLose()
    {
        return Lost;
    }
    sf::RectangleShape square;
    sf::RectangleShape square2;

private:
    Event evn;
    float i = 0.550;
    int level = 1;
    int catchCount = 0;
    bool Lost = 0;
    bool win = false;
    void initSprite();
    void initText();
    void initAudio();
    std::string audioFile2 = "res/Ring_Victor059.wav";
    std::string audioFile1 = "res/Generic-Beep_Victor059.wav";
    std::string audioFile3 = "res/Ring-Deep_Victor059.wav";

    //Variables
    Font pix;
    Text resultWL;
    Text Catch;
    Text CatchT;
    Text Speed;
    Text SpeedT;
    Text Level;
    Text LevelT;
    Text Score;
    Text ScoreT;
    Sound beep1;
    Sound levl;
    Sound lose;
    SoundBuffer buffer1;
    SoundBuffer buffer2;
    SoundBuffer buffer3;
};

#endif // CATCHTHEBLOCK_H
