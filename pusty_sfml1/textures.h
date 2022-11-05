#ifndef textures_h
#define textures_h

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>

class Textures
{
private:
    const std::vector<sf::Texture> tab;
public:
    enum class Id{background=0, flower1, flower2, flower3, flower4, flower5, flower6, flower_last,
                  trush1, trush2, trush3, trush4, trush5, trush6, trush_last};


public:
    Textures();
    ~Textures(){};
    const sf::Texture* operator[](Id id);
private:
    sf::Texture readFromFile(std::string file_path);
};

#endif
