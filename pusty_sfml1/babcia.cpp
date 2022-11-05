#include "babcia.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

//Konstruktor
Babcia::Babcia(sf::Vector2f position, sf::Texture &texture6)
{
    setPosition(position);
    setTexture(texture6);
}

