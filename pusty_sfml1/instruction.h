#ifndef instruction_h
#define instruction_h

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <memory>
#include <fstream>
#include <windows.h>

#include "textures.h"
#include "picture.h"
#include "mouseandcursor.h"
#include "fonts.h"
#include "button.h"

class Instruction
{
protected:
    sf::RenderWindow *window;

    Textures textures;
    std::vector<std::unique_ptr<Picture>>gameObjects;

    Fonts fonts;
    std::vector<sf::Text> text;

    MouseAndCursor mouse;

    std::vector <Button> buttons;

    bool nextGame;

    std::string link;

public:
    Instruction(sf::RenderWindow *window_, std::string textInstruction, std::string link_ = "");
    ~Instruction();

protected:
    int gameLoop();
    sf::Text createText(std::string text, const sf::Font &font, unsigned int characterSize, sf::Color color,
                        int x, int y);

    void eventsMouseAndWindow();
    void drawing();
    void goNext();
    void readMore();

};

#endif
