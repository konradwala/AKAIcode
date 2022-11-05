#ifndef PLATFORMA_H
#define PLATFORMA_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Platforma : public sf::Sprite
{
public:
    Platforma(sf::Vector2f position, sf::Texture &texture4);
};

#endif // PLATFORMA_H
