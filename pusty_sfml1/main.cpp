#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "zbieranie_smieci.h"
#include "instruction.h"
#include "WashingHandsClass.h"
#include "project.h"
#include "gra_zakupy.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    srand(time(NULL));

    window.setFramerateLimit(100);

    Instruction startScreen(&window, "Witaj, podaj swoje imie");

    Instruction instruction3(&window, "Zbieraj zdrowe jedzenie");
    Food game3("Player_1", &window);
    Instruction instruction3a(&window, "Pamietaj, zeby dobrze sie odzywiac", "https://foodsbyann.com/Zdrowe-jedzenie-najwazniejsze-zasady-zdrowego-odzywiania-blog-pol-1610546125.html");

    Instruction instruction1(&window, "Zbierz wszystkie smieci, UWAGA nie zrywaj kwiatkow");
    zbieranieSmieci game1("Player_1", &window);
    Instruction instruction1a(&window, "Pamietaj, zeby nie smiecic", "http://zielonainfrastruktura.pl/zbieranie-smieci-i-dbanie-o-srodowisko/");

    Instruction instruction4(&window, "Dostarcz zakupy starszej osobie");
    Gra_Zakupy game4(&window);
    Instruction instruction4a(&window, "Pamietaj o pomaganiu starszym osobom", "https://zdrowie.pap.pl/wywiady/senior/drobne-gesty-pomagaja-starszym-ludziom-poradzic-sobie-z-samotnoscia");

    Instruction instruction2(&window, "Dokladnie umyj rece - przy pomocy mydla a nastepnie wody");
    WashingHands game2("Player_1", &window);
    Instruction instruction2a(&window, "Pamietaj, zeby myc rece", "https://www.gov.pl/web/gis/jak-myc-rece-instrukcja-mycia-rak");


    window.close();

    return 0;
}
