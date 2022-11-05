#ifndef fonts_h
#define fonts_h

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>

class Fonts
{
private:
    const std::vector<sf::Font> tab;
public:
    enum class Id{arial=0};

public:
    Fonts();
    ~Fonts(){};
    const sf::Font* operator[](Id id);
private:
    sf::Font readFromFile(std::string file_path);
};

#endif
