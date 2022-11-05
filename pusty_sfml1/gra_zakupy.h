#ifndef GRA_ZAKUPY_H
#define GRA_ZAKUPY_H
#include <iostream>
using namespace std;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>

#include "platforma.h"


class Gra_Zakupy
{
public:
    Gra_Zakupy(sf::RenderWindow *window);
    void play(sf::RenderWindow *window, string nick);
    //Tworzenie levela
    void LevelMaking (std::vector<std::unique_ptr<sf::Sprite>> &MovingObjects, sf::Texture &Tex_Platforma)
    {
        sf::Vector2f kontener;

            kontener={100,500};
            MovingObjects.emplace_back(std::make_unique<Platforma>(Platforma(kontener,Tex_Platforma)));

            kontener={275,350};
            MovingObjects.emplace_back(std::make_unique<Platforma>(Platforma(kontener,Tex_Platforma)));

            kontener={700,590};
            MovingObjects.emplace_back(std::make_unique<Platforma>(Platforma(kontener,Tex_Platforma)));

            kontener={600,590};
            MovingObjects.emplace_back(std::make_unique<Platforma>(Platforma(kontener,Tex_Platforma)));

            kontener={450,200};
            MovingObjects.emplace_back(std::make_unique<Platforma>(Platforma(kontener,Tex_Platforma)));

            kontener={450,500};
            MovingObjects.emplace_back(std::make_unique<Platforma>(Platforma(kontener,Tex_Platforma)));

            kontener={700,300};
            MovingObjects.emplace_back(std::make_unique<Platforma>(Platforma(kontener,Tex_Platforma)));

    }
};

#endif // GRA_ZAKUPY_H
