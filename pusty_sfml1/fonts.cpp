#include "fonts.h"

Fonts::Fonts()
    : tab{readFromFile("fonts/arial.ttf")}
{
    ;
}

const sf::Font* Fonts::operator[](Id id)
{
    return &tab[static_cast<int>(id)];
}

sf::Font Fonts::readFromFile(std::string file_path)
{
    sf::Font font;
    if(!font.loadFromFile(file_path))
    {
        std::cout<<"Nie mozna odczytac pliku: "<<file_path<<std::endl;
    }
    return font;
}
