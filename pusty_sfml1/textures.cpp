#include "textures.h"

Textures::Textures()
    : tab{readFromFile("textures/background.bmp"),
          readFromFile("textures/flower1.bmp"),
          readFromFile("textures/flower2.bmp"),
          readFromFile("textures/flower3.bmp"),
          readFromFile("textures/flower4.bmp"),
          readFromFile("textures/flower5.bmp"),
          readFromFile("textures/flower6.bmp"),
          readFromFile("textures/flower_last.bmp"),
          readFromFile("textures/trush1.bmp"),
          readFromFile("textures/trush2.bmp"),
          readFromFile("textures/trush3.bmp"),
          readFromFile("textures/trush4.bmp"),
          readFromFile("textures/trush5.bmp"),
          readFromFile("textures/trush6.bmp"),
          readFromFile("textures/trush_last.bmp")}
{
    ;
}

const sf::Texture* Textures::operator[](Id id)
{
    return &tab[static_cast<int>(id)];
}

sf::Texture Textures::readFromFile(std::string file_path)
{
    sf::Texture texture;
    if(!texture.loadFromFile(file_path))
    {
        std::cout<<"Nie mozna odczytac pliku: "<<file_path<<std::endl;
        texture.create(10, 10);
    }
    return texture;
}
