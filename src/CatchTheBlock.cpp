#include "CatchTheBlock.h"

using namespace sf;

CatchTheBlock::CatchTheBlock()
{
    //Initialize the variables
    initAudio();
    initSprite();
    initText();

}

CatchTheBlock::~CatchTheBlock()
{

}

void CatchTheBlock::initSprite()
{
    //Block
    square.setSize(Vector2f(100.0f, 100.0f));
    square.setPosition(600.5f,-100.f);
    square.setOutlineColor(Color::White);
    square.setFillColor(Color::Black);
    square.setOutlineThickness(1.0f);

    //Player
    square2.setSize(Vector2f(50.0f, 50.0f));
    square2.setFillColor(Color::Red);
}

void CatchTheBlock::initAudio()
{
    //Audio setting
    buffer3.loadFromFile(audioFile3);
    buffer2.loadFromFile(audioFile2);
    buffer1.loadFromFile(audioFile1);
    beep1.setBuffer(buffer1);
    levl.setBuffer(buffer2);
    lose.setBuffer(buffer3);
}

void CatchTheBlock::initText()
{
    //Font
    pix.loadFromFile("res/consola.ttf");

    //Catch Text
    CatchT.setFont(pix);
    CatchT.setPosition(0,0);
    CatchT.setFillColor(menu.getTextColor());
    CatchT.setString("Catches: ");
    Catch.setCharacterSize(24);
    Catch.setFont(pix);
    Catch.setPosition(140,0);
    Catch.setFillColor(menu.getTextColor());
    Catch.setCharacterSize(30);
    Catch.setString(std::to_string(catchCount));

    //Speed Text
    SpeedT.setFont(pix);
    SpeedT.setPosition(0,25);
    SpeedT.setFillColor(menu.getTextColor());
    SpeedT.setString("Speed: ");
    Speed.setCharacterSize(24);
    Speed.setFont(pix);
    Speed.setPosition(105,25);
    Speed.setFillColor(menu.getTextColor());
    Speed.setCharacterSize(30);
    Speed.setString(std::to_string(i));

    //Win or Lose Text
    resultWL.setFillColor(Color::White);
    resultWL.setFont(pix);
    resultWL.setCharacterSize(128);
    resultWL.setPosition( 1280 / 3.5, 720 / 2.85);

    //Level Text
    LevelT.setFont(pix);
    LevelT.setPosition(0,50);
    LevelT.setFillColor(menu.getTextColor());
    LevelT.setString("Level: ");
    Level.setCharacterSize(24);
    Level.setFont(pix);
    Level.setPosition(105,50);
    Level.setFillColor(menu.getTextColor());
    Level.setCharacterSize(30);
    Level.setString(std::to_string(level));
}

void CatchTheBlock::render(RenderTarget& target)
{
    if(menu.getGameStart() == true && menu.getGamePause() == false)
    {
        target.draw(resultWL);
        target.draw(square2);
        target.draw(square);
        target.draw(Catch);
        target.draw(CatchT);
        target.draw(Speed);
        target.draw(SpeedT);
        target.draw(Level);
        target.draw(LevelT);
    }
    if(menu.getGameStart() == false)
    {
        menu.render(target);
    }
    if(menu.getGamePause() == true)
    {
        menu.renderPause(target);
    }
}

void CatchTheBlock::update(Window& target)
{
    if(menu.getGameStart() == true)
    {
        if(square.getPosition().y < target.getSize().y && !getGameWin() && !menu.getGamePause() && !Lost && target.hasFocus())
        {
            target.setMouseCursorVisible(false);
            Mouse::setPosition(Vector2i( Mouse::getPosition().x,square2.getPosition().y + 250));
            square2.setPosition(Mouse::getPosition().x - 350, 500);
            square.move(0., i);
            if(square2.getGlobalBounds().intersects(square.getGlobalBounds()))
            {
                square.setPosition(10+(rand()%1100),0.f);
                catchCount++;
                beep1.play();
                if(!Lost || !win)
                {
                    for(int l = 1; l<40; l++)
                    {
                        if(catchCount == l)
                        {
                            i = i + 0.025;
                            l++;
                        }
                        else if (catchCount == 40)
                        {
                            i = 0;
                            win = true;
                            break;
                        }
                        else if(Lost == true)
                        {
                            break;
                        }
                    }
                }
                Catch.setString(std::to_string(catchCount));
                Speed.setString(std::to_string(i));
            }
        }
        if(square.getPosition().y >= target.getSize().y)
        {
            Lost = true;
            square.setOutlineColor(Color::Black);
            Mouse::setPosition(Vector2i( Mouse::getPosition().x,Mouse::getPosition().y));
            target.setMouseCursorVisible(true);
            resultWL.setString("You Lost");
            if(Keyboard::isKeyPressed(Keyboard::Key::Space) || (Mouse::isButtonPressed(Mouse::Button::Left) && target.hasFocus() == true))
            {
                Lost = false;
                lose.setLoop(false);
                lose.play();
                square.setOutlineColor(Color::White);
                catchCount = 0;
                i = 0.550;
                resultWL.setString("");
                square.setPosition(600.5f,-100.f);
                Catch.setString(std::to_string(catchCount));
                Speed.setString(std::to_string(i));
                Level.setString(std::to_string(level));
            }
        }
        if (getGameWin() == true)
        {
            square.setOutlineColor(Color::Black);
            Mouse::setPosition(Vector2i( Mouse::getPosition().x,Mouse::getPosition().y));
            target.setMouseCursorVisible(true);
            resultWL.setString("You Won");
            if(Keyboard::isKeyPressed(Keyboard::Key::Space) || Mouse::isButtonPressed(Mouse::Button::Left) && target.hasFocus() == true)
            {
                setGameWin(false);
                levl.setLoop(false);
                levl.play();
                square.setOutlineColor(Color::White);
                resultWL.setString("");
                square.setPosition(600.5f,-100.f);
                if(square.getSize().x < 20.f || level == 5)
                {
                    level = 0;
                    square.setSize(Vector2f(100.f, 100.f));
                }
                else
                {
                    level++;
                    square.setSize(Vector2f(square.getSize().x - 20, square.getSize().y - 20));
                }
                catchCount = 0;
                i = 0.550;
                Catch.setString(std::to_string(catchCount));
                Speed.setString(std::to_string(i));
                Level.setString(std::to_string(level));
            }
        }
    }
    else if(!menu.getGameStart() && !menu.getQuit())
    {
        menu.update(target);
    }
    else if(menu.getQuit())
    {
        target.close();
    }
    if(menu.getGamePause() && square.getPosition().y >=! target.getSize().y)
    {
        target.setMouseCursorVisible(true);
        square2.setPosition(square2.getPosition().x, square2.getPosition().y);
        //Mouse::setPosition(Vector2i(square2.getPosition().x + 350, square2.getPosition().y));
    }
}
