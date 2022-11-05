#include "platforma.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

//Konstruktor
Platforma::Platforma(sf::Vector2f position, sf::Texture &texture4)
{
    setPosition(position);
    setTexture(texture4);
}
