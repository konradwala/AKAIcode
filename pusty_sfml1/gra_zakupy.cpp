#include <wolontariusz.h>
#include <platforma.h>
#include <babcia.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <ctime>
#include <random>
#include <iostream>
#include <memory>
#include <cstdlib>
#include <gra_zakupy.h>


Gra_Zakupy::Gra_Zakupy(sf::RenderWindow *window)
{
    srand(time(NULL));
    //Tworzenie okna
    window->setFramerateLimit(120);



    //Tworzenie napisu
    sf::Text GameName;
    sf::Text GameName2;
    sf::Text GameName3;
    sf::Font font;
    font.loadFromFile("fonty/OpenSansIT.ttf");
    GameName.setFont(font);
    GameName.setString("Zakupy: ");
    GameName.setCharacterSize(40);
    GameName.setFillColor(sf::Color::Black);
    GameName.setOutlineThickness(1.5);
    GameName.setOutlineColor(sf::Color::White);
    GameName.setStyle(sf::Text::Bold);
    GameName.setPosition(10,10);

    //Wgrywanie tekstur
    sf::Texture Tex_Character1;
    sf::Texture Tex_Platforma;
    sf::Texture Tex_Babcia;
    sf::Texture Tex_Tlo;
    sf::Texture Tex_Watermelon;
    sf::Texture Tex_Drugs;
    sf::Texture Tex_Eggs;
    sf::Texture Tex_Strawberries;
    Tex_Character1.loadFromFile("tekstury/character1.png");
    Tex_Platforma.loadFromFile("tekstury/platforma.png");
    Tex_Babcia.loadFromFile("tekstury/grandma.png");
    Tex_Tlo.loadFromFile("tekstury/tlo.png");
    Tex_Watermelon.loadFromFile("tekstury/watermelon.png");
    Tex_Drugs.loadFromFile("tekstury/drugs.png");
    Tex_Eggs.loadFromFile("tekstury/eggs.png");
    Tex_Strawberries.loadFromFile("tekstury/strawberries.png");

    //Tworzenie zakupów
    sf::Sprite Truskawka;
    Truskawka.setTexture(Tex_Strawberries);
    Truskawka.setPosition(700,180);
    Truskawka.setScale(0.1,0.1);
    sf::Sprite Arbuz;
    Arbuz.setTexture(Tex_Watermelon);
    Arbuz.setPosition(275,250);
    Arbuz.setScale(0.1,0.1);
    sf::Sprite Jajka;
    Jajka.setTexture(Tex_Eggs);
    Jajka.setPosition(450,400);
    Jajka.setScale(0.07,0.07);
    sf::Sprite Leki;
    Leki.setTexture(Tex_Drugs);
    Leki.setPosition(470,120);
    Leki.setScale(0.075,0.075);

    //Załadowywanie tła
    sf::Sprite Tlo;
    Tlo.setTexture(Tex_Tlo);

    //Tworzenie wolontariusza
    sf::Vector2f Pozycja_startowa(100, 300);
    Wolontariusz gracz(Pozycja_startowa, Tex_Character1);

    GameName2.setFont(font);
    GameName2.setString(std::to_string(gracz.GetPoints()));
    GameName2.setCharacterSize(40);
    GameName2.setFillColor(sf::Color::Black);
    GameName2.setOutlineThickness(1.5);
    GameName2.setOutlineColor(sf::Color::White);
    GameName2.setStyle(sf::Text::Bold);
    GameName2.setPosition(160,10);

    GameName3.setFont(font);
    GameName3.setString("/4");
    GameName3.setCharacterSize(40);
    GameName3.setFillColor(sf::Color::Black);
    GameName3.setOutlineThickness(1.5);
    GameName3.setOutlineColor(sf::Color::White);
    GameName3.setStyle(sf::Text::Bold);
    GameName3.setPosition(180,10);

    std::vector<std::unique_ptr<sf::Sprite>> MovingObjects;

    LevelMaking(MovingObjects, Tex_Platforma);

    //Tworzenie babci
    sf::Vector2f position2(700, 500);
    Babcia target(position2, Tex_Babcia);
    target.setScale(0.2,0.2);

    //Prędkość grawitacji
    float Gravity_speed=4;

    //Przydatne zmienne
    bool is_onGround=false;
    float velocityY=0;
    float velocityX=0;

    //Oscylowanie czasem
    sf::Clock clock;
    sf::Clock clock2;
    sf::Time time;
    float Time_sum=0;
    float Time_sum2=0;

    bool koniec_gry = 0;

    //Główna pętla gry
    while (window->isOpen() && !koniec_gry)
    {
        //Pobieranie czasu
        sf::Time elapsed1 = clock.getElapsedTime();
        Time_sum+=elapsed1.asSeconds();
        sf::Time elapsed2 = clock2.getElapsedTime();
        Time_sum2+=elapsed2.asSeconds();

        //Poruszanie się gracza w lewo
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            velocityX=-1;
            Time_sum2 = 0;
            clock2.restart();
        }

        //Poruszanie się gracza w prawo
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            velocityX=1;
            Time_sum2 = 0;
            clock2.restart();
        }

        //Skok
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && is_onGround==true)
        {
            velocityY=10;
            Time_sum = 0;
            clock.restart();
        }

        //Grawitacja
        if(Time_sum < 3)
        {
            gracz.move(0,-velocityY);
        }
        if(Time_sum >= 3)
        {
            velocityY=0;
        }

        //Poruszanie prawo lewo
        if(Time_sum2 < 3)
        {
            gracz.move(velocityX,0);
        }
        if(Time_sum2 >= 3)
        {
            velocityX=0;
        }

        is_onGround = false;

        //Obsługa zdarzeń
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        //Kolizja z granicami ekranu
        gracz.GraniceEkranu(gracz.getGlobalBounds());

        //Kolizja z zakupami
        if(gracz.getGlobalBounds().intersects(target.getGlobalBounds()) && gracz.GetPoints()==4)
        {
            std::cout << "Udalo ci sie dostarczyc zakupy do babci!" << std::endl;
            //window->close();
            koniec_gry = 1;
        }

        if(gracz.getGlobalBounds().intersects(Truskawka.getGlobalBounds()))
        {
                gracz.SetPoints();
                std::cout << gracz.GetPoints() <<std::endl;
                Truskawka.setPosition(10000,10000);

        }
        if(gracz.getGlobalBounds().intersects(Arbuz.getGlobalBounds()))
        {
                gracz.SetPoints();
                std::cout << gracz.GetPoints() <<std::endl;
                Arbuz.setPosition(10000,10000);
        }
        if(gracz.getGlobalBounds().intersects(Jajka.getGlobalBounds()))
        {
                gracz.SetPoints();
                std::cout << gracz.GetPoints() <<std::endl;
                Jajka.setPosition(10000,10000);
        }
        if(gracz.getGlobalBounds().intersects(Leki.getGlobalBounds()))
        {
                gracz.SetPoints();
                std::cout << gracz.GetPoints() <<std::endl;
                Leki.setPosition(10000,10000);
        }

        //Wywoływanie funkcji dla platform
        for (size_t i = 0; i < MovingObjects.size(); i++) {
            Platforma *platforma = dynamic_cast<Platforma *>(MovingObjects[i].get());
            if (platforma != nullptr) {
                if(gracz.getGlobalBounds().intersects(platforma->getGlobalBounds())){
                    if(gracz.getGlobalBounds().top+gracz.getGlobalBounds().height <= platforma->getGlobalBounds().top +platforma->getGlobalBounds().height)
                    {
                        is_onGround=true;
                    }
                }
            }
        }

        GameName2.setString(std::to_string(gracz.GetPoints()));

        //Grawitacja gracza
        if(is_onGround==false)
        {
            gracz.move(0, Gravity_speed);
        }

        //Rysowanie obiektów na ekranie
        window->clear(sf::Color::Black);
        window->draw(Tlo);
        window->draw(gracz);
        window->draw(target);
        window->draw(Jajka);
        window->draw(Arbuz);
        window->draw(Truskawka);
        window->draw(Leki);
        window->draw(GameName);
        window->draw(GameName2);
        window->draw(GameName3);
        for(const auto &s : MovingObjects) {
            window->draw(*s);
        }
        window->display();
    }

    std::fstream plik;
    plik.open("result.thx", std::ios::app);

    plik<<"Player_1"<<" "<<static_cast<int>(time.asSeconds())<<std::endl;

    plik.close();
    plik.clear();

}
