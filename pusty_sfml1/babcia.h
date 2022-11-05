#ifndef BABCIA_H
#define BABCIA_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Babcia : public sf::Sprite
{
public:
    Babcia(sf::Vector2f position, sf::Texture &texture6);
};

#endif // BABCIA_H

