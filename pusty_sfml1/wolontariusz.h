#ifndef WOLONTARIUSZ_H
#define WOLONTARIUSZ_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Wolontariusz : public sf::Sprite
{
private:
   int Velocity_X=1;
   int Points=0;
   bool CanOpenDoor=false;

public:
    Wolontariusz(sf::Vector2f position, sf::Texture &texture);
    void Movement(int wybor);
    void GraniceEkranu(sf::FloatRect scianki);
    void TextureSetter(sf::Texture &texture);
    void SetPoints();
    int  GetPoints();
    void  SetKey();
    bool GetKey();
};

#endif // WOLONTARIUSZ_H
