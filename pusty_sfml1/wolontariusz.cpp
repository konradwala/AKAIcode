#include "wolontariusz.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

//Konstruktor
Wolontariusz::Wolontariusz(sf::Vector2f position, sf::Texture &texture)
{
    setPosition(position);
    setTexture(texture);
    setScale(0.1,0.1);
}

//Zachowanie przy kolizji z krawędziami
void Wolontariusz::GraniceEkranu(sf::FloatRect scianki)
 {
    if(scianki.left < 0)
    {
        setPosition(100,300);
    }
    if(scianki.left+scianki.width > 800)
    {
        setPosition(100,300);
    }
    if(scianki.top+scianki.height > 600)
    {
        setPosition(100,300);
    }
 }

//Poruszanie się postaci
void Wolontariusz::Movement(int wybor)
{
    if(wybor==0)
    {
        move(0,0);
    }
    if(wybor==1)
    {
        move(-Velocity_X,0);
    }
    if(wybor==2)
    {
        move(Velocity_X,0);
    }
}

//Podmiana tekstury
void Wolontariusz::TextureSetter(sf::Texture &texture)
{
    setTexture(texture);
}

//Dodawanie punktów
void Wolontariusz::SetPoints()
{
    Points++;
}

//Pobieranie ilości punktów
int Wolontariusz::GetPoints()
{
    return Points;
}
