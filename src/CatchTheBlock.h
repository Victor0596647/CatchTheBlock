#ifndef CATCHTHEBLOCK_H
#define CATCHTHEBLOCK_H
#include "game.h"

using namespace sf;

class CatchTheBlock
{
    public:
        game Game;
        CatchTheBlock();
        virtual ~CatchTheBlock();
        void update();
        void run();
        void render();
        void updatePollEvents();
        bool win = false;

    private:
        float i = 0.550;
        int level = 1;
        int catchCount = 0;
        bool setPause = 0;
        bool Lost = 0;
        void initSprite();
        void initText();
        void initAudio();
        void initWin();
        std::string audioFile2 = "Ring_Victor059.wav";
        std::string audioFile1 = "Generic-Beep_Victor059.wav";
        std::string audioFile3 = "AchieveDeep_Victor059.wav";

        //Variables
        Font pix;
        Text resultWL;
        Text Catch;
        Text CatchT;
        Text Speed;
        Text SpeedT;
        Text Level;
        Text LevelT;
        sf::RectangleShape square;
        sf::RectangleShape square2;
        Sound beep1;
        Sound levl;
        Sound lose;
        SoundBuffer buffer1;
        SoundBuffer buffer2;
        SoundBuffer buffer3;
};

#endif //CATCHTHEBLOCK_H
