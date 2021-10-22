#include "mainMenu.h"


mainMenu::mainMenu()
{
    initText();
}

mainMenu::~mainMenu()
{
    //dtor
}

void mainMenu::render(RenderTarget &target){
    target.draw(mainMenu::mainTitle);
}

void mainMenu::update(){

}

void mainMenu::initText(){
    pix.loadFromFile("consola.ttf");

    mainTitle.setFont(pix);
    mainTitle.setCharacterSize(40);
    mainTitle.setFillColor(Color::Red);
    mainTitle.setString("Catch The Block");
    mainPlay.setFont(pix);
    mainOptions.setFont(pix);
    mainQuit.setFont(pix);
}
