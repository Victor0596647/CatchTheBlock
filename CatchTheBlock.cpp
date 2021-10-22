#include "CatchTheBlock.h"
#include <SFML/Audio.hpp>

CatchTheBlock::CatchTheBlock()
{
    //Initialize the variables
    initAudio();
    initSprite();
    initText();
    //Game
    run();
}

CatchTheBlock::~CatchTheBlock()
{

}

void CatchTheBlock::run(){
    while(Game.app->isOpen()){
        updatePollEvents();
        render();
    }
}

void CatchTheBlock::initSprite(){
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

void CatchTheBlock::initAudio(){
    //Audio setting
    buffer3.loadFromFile(audioFile3);
    buffer2.loadFromFile(audioFile2);
    buffer1.loadFromFile(audioFile1);
    beep1.setBuffer(buffer1);
    levl.setBuffer(buffer2);
    lose.setBuffer(buffer3);
}

void CatchTheBlock::initText(){
    //Font
    pix.loadFromFile("consola.ttf");

    //Catch Text
    CatchT.setFont(pix);
    CatchT.setPosition(0,0);
    CatchT.setFillColor(Color::White);
    CatchT.setString("Catches: ");
    Catch.setCharacterSize(24);
    Catch.setFont(pix);
    Catch.setPosition(140,0);
    Catch.setFillColor(Color::White);
    Catch.setCharacterSize(30);
    Catch.setString(std::to_string(catchCount));

    //Speed Text
    SpeedT.setFont(pix);
    SpeedT.setPosition(0,25);
    SpeedT.setFillColor(Color::White);
    SpeedT.setString("Speed: ");
    Speed.setCharacterSize(24);
    Speed.setFont(pix);
    Speed.setPosition(105,25);
    Speed.setFillColor(Color::White);
    Speed.setCharacterSize(30);
    Speed.setString(std::to_string(i));

    //Win or Lose Text
    resultWL.setFillColor(Color::White);
    resultWL.setFont(pix);
    resultWL.setCharacterSize(128);
    resultWL.setPosition(Game.app->getSize().x / 3.5, Game.app->getSize().y / 2.85);

    //Level Text
    LevelT.setFont(pix);
    LevelT.setPosition(0,50);
    LevelT.setFillColor(Color::White);
    LevelT.setString("Level: ");
    Level.setCharacterSize(24);
    Level.setFont(pix);
    Level.setPosition(105,50);
    Level.setFillColor(Color::White);
    Level.setCharacterSize(30);
    Level.setString(std::to_string(level));
}

void CatchTheBlock::render(){
    Game.app->clear();
    Game.app->draw(resultWL);
    Game.app->draw(square2);
    Game.app->draw(square);
    Game.app->draw(Catch);
    Game.app->draw(CatchT);
    Game.app->draw(Speed);
    Game.app->draw(SpeedT);
    Game.app->draw(Level);
    Game.app->draw(LevelT);
    Game.app->display();
}

void CatchTheBlock::update(){
    if(square.getPosition().y < Game.app->getSize().y && !win && !setPause && !Lost){
            Mouse::setPosition(Vector2i( Mouse::getPosition().x,square2.getPosition().y));
            Game.app->setMouseCursorVisible(false);
            square2.setPosition(Mouse::getPosition().x - 350, 500);
            square.move(0., i);
            if(square2.getGlobalBounds().intersects(square.getGlobalBounds())){
                square.setPosition(10+(rand()%1100),0.f);
                catchCount++;
                beep1.play();
                if(!Lost || !win){
                    for(int l = 1; l<40; l++){
                        if(catchCount == l){
                            i = i + 0.025;
                            l++;
                        }else if (catchCount == 40){
                            i = 0;
                            win = true;
                            break;
                        }else if(Lost == true){
                            break;
                        }
                    }
                }
                //system("CLS");
                //std::cout<<"Speed: "<<i<<std::endl;
                //std::cout<<"Catches: "<<catchCount<<std::endl;
                Catch.setString(std::to_string(catchCount));
                Speed.setString(std::to_string(i));
            }
        }
        if(square.getPosition().y >= Game.app->getSize().y){
            Lost = true;
            square.setOutlineColor(Color::Black);
            Mouse::setPosition(Vector2i( Mouse::getPosition().x,Mouse::getPosition().y));
            Game.app->setMouseCursorVisible(true);
            resultWL.setString("You Lose");
            if(Keyboard::isKeyPressed(Keyboard::Key::Space)){
                Lost = false;
                lose.setLoop(false);
                lose.play();
                square.setOutlineColor(Color::White);
                catchCount = 0;
                i = 0.550;
                resultWL.setString("");
                square.setPosition(600.5f,-100.f);
                //system("CLS");
                //std::cout<<"Speed: "<<i<<std::endl;
                //std::cout<<"Catches: "<<catchCount<<std::endl;
                Catch.setString(std::to_string(catchCount));
                Speed.setString(std::to_string(i));
                Level.setString(std::to_string(level));
            }
        }
        if (win == true){
            square.setOutlineColor(Color::Black);
            Mouse::setPosition(Vector2i( Mouse::getPosition().x,Mouse::getPosition().y));
            Game.app->setMouseCursorVisible(true);
            resultWL.setString("You Win");
            if(Keyboard::isKeyPressed(Keyboard::Key::Space)){
                win = false;
                levl.setLoop(false);
                levl.play();
                square.setOutlineColor(Color::White);
                resultWL.setString("");
                square.setPosition(600.5f,-100.f);
                if(square.getSize().x < 20.f || level == 5){
                    level = 1;
                    square.setSize(Vector2f(100.f, 100.f));
                }else {
                    level++;
                    square.setSize(Vector2f(square.getSize().x - 20, square.getSize().y - 20));
                }
                catchCount = 0;
                i = 0.550;
                //system("CLS");
                //std::cout<<"Speed: "<<i<<std::endl;
                //std::cout<<"Catches: "<<catchCount<<std::endl;
                Catch.setString(std::to_string(catchCount));
                Speed.setString(std::to_string(i));
                Level.setString(std::to_string(level));
            }
        }
        if(setPause && square.getPosition().y != Game.app->getSize().y){
            Mouse::setPosition(Vector2i(square2.getPosition().x, square2.getPosition().y));
        }
}

void CatchTheBlock::updatePollEvents(){
    Event event;
    while(Game.app->pollEvent(event)){
        switch (event.type){
            case Event::Closed:
                Game.app->close();
                break;
            case Event::KeyPressed:
                if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){
                    Game.app->close();
                }
            case Event::KeyReleased:
                if(Keyboard::isKeyPressed(Keyboard::Key::P) && win == false && Lost == false){
                    if(setPause == 1){
                        setPause = 0;
                        Mouse::setPosition(Vector2i( Mouse::getPosition().x + 350, square2.getPosition().y));
                }else if(setPause == 0) {
                    setPause = 1;
                }
            }
        }
    }
    update();
}
