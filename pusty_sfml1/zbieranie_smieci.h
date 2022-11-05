#ifndef zbieranie_smieci_h
#define zbieranie_smieci_h

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <memory>
#include <fstream>

#include "textures.h"
#include "picture.h"
#include "mouseandcursor.h"
#include "fonts.h"


class zbieranieSmieci
{
    sf::RenderWindow *window;
    std::string name;

    Textures textures;
    std::vector<std::unique_ptr<Picture>>gameObjects;

    Fonts fonts;
    sf::Text textResultTime;

    MouseAndCursor mouse;

    float timeResult;

    std::string testUsunac;

public:
    zbieranieSmieci(std::string name_, sf::RenderWindow *window_);
    ~zbieranieSmieci();

private:
    void createObjects(unsigned int numberOfFlowers, unsigned int numberOfThrashes);
    int gameLoop();
    void eventsMouseAndWindow();
    void drawing();
    sf::IntRect randPosition();

    sf::Text createText(std::string text, const sf::Font &font, unsigned int characterSize, sf::Color color,
                        int x, int y);

    void savingResult();
};


#endif
