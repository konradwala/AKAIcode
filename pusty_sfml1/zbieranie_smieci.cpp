#include "zbieranie_smieci.h"

zbieranieSmieci::zbieranieSmieci(std::string name_, sf::RenderWindow *window_):mouse(window_)
{
    testUsunac = "";
    window = window_;
    name = name_;

    gameObjects.emplace_back(std::make_unique<Picture>(textures[Textures::Id::background], window, 0, 0, 800, 600,
                             Textures::Id::background));
    createObjects(10, 15);

    timeResult = 0.0;

    textResultTime = createText(std::to_string(round(timeResult*10.0)/10.0), *fonts[Fonts::Id::arial], 36, sf::Color::White, 800, 5);

    gameLoop();
}

zbieranieSmieci::~zbieranieSmieci()
{
    ;
}

sf::IntRect zbieranieSmieci::randPosition()
{
    sf::IntRect randPos;
    randPos.height = randPos.width = 40+rand()%40;

    randPos.left = rand()%(800-randPos.width);
    randPos.top = rand()%(600-randPos.height);

    for(unsigned int i=0; i<gameObjects.size(); i++)
    {
        if(gameObjects[i]->getId() >= Textures::Id::flower1 &&  gameObjects[i]->getId() <= Textures::Id::trush_last)
        {
            if(gameObjects[i]->getGlobalBounds().intersects(static_cast<sf::FloatRect>(randPos)))
            {
                randPos.left = rand()%(800-randPos.width);
                randPos.top = rand()%(600-randPos.height);
                i = 0;
            }
        }
    }

    return randPos;
}

sf::Text zbieranieSmieci::createText(std::string text, const sf::Font &font, unsigned int characterSize, sf::Color color, int x, int y)
{
    sf::Text text_(text, font, characterSize);
    text_.setPosition(x+80, y);
    text_.setFillColor(color);
    text_.setOrigin(text_.getLocalBounds().width, 0);

    return text_;
}

void zbieranieSmieci::savingResult()
{
    std::fstream plik;
    plik.open("result.thx", std::ios::app);

    plik<<name<<" "<<static_cast<int>(timeResult)<<std::endl;

    plik.close();
    plik.clear();

}

void zbieranieSmieci::createObjects(unsigned int numberOfFlowers, unsigned int numberOfThrashes)
{
    //generating flowers
    for(unsigned int i=0; i<numberOfFlowers; i++)
    {
        if(gameObjects.size() <= 40)
        {
            sf::IntRect randPos = randPosition();
            int min = static_cast<int>(Textures::Id::flower1);
            int max = static_cast<int>(Textures::Id::flower_last);
            Textures::Id randId = static_cast<Textures::Id>(min+rand()%(max-min));
            gameObjects.emplace_back(std::make_unique<Picture>(textures[randId], window, randPos.left, randPos.top,
                                     randPos.width, randPos.height, Textures::Id::flower1));
            gameObjects[gameObjects.size()-1]->setRotation(static_cast<Picture::Rotation>((rand()%4)*90));
        }

    }

    //generating trushes
    for(unsigned int i=0; i<numberOfThrashes; i++)
    {
        if(gameObjects.size() <= 40)
        {
            sf::IntRect randPos = randPosition();
            int min = static_cast<int>(Textures::Id::trush1);
            int max = static_cast<int>(Textures::Id::trush_last);
            Textures::Id randId = static_cast<Textures::Id>(min+rand()%(max-min));
            gameObjects.emplace_back(std::make_unique<Picture>(textures[randId], window, randPos.left, randPos.top,
                                     randPos.width, randPos.height, Textures::Id::trush1));
            gameObjects[gameObjects.size()-1]->setRotation(static_cast<Picture::Rotation>((rand()%4)*90));
        }

    }
}

int zbieranieSmieci::gameLoop()
{
    window->setFramerateLimit(100);

    sf::Clock clock;
    float elapsed;
    while (window->isOpen())
    {
        elapsed = clock.restart().asSeconds();

        timeResult += elapsed;

        textResultTime = createText(std::to_string(round(timeResult*10.0)/10.0), *fonts[Fonts::Id::arial], 36, sf::Color::White, 800, 5);

        eventsMouseAndWindow();

        drawing();

        if(std::count_if(gameObjects.begin(), gameObjects.end(), [](std::unique_ptr<Picture> &obj)
            {if(obj->getId() >= Textures::Id::trush1 && obj->getId() <= Textures::Id::trush_last){return 1;} return 0;}) == 0)
        {
            savingResult();
            return 0;
        }
    }
    return 0;
}

void zbieranieSmieci::eventsMouseAndWindow()
{
    mouse.thisFrameType = MouseAndCursor::Arrow;
    mouse.clicked_left = 0;
    mouse.clicked_right = 0;
    sf::Vector2i mousePosition = mouse.getPosition(*window);

    sf::Event event;
    while (window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            window->close();
        }
        if(event.type == sf::Event::MouseButtonPressed)
        {
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                mouse.clicked_left = 1;

            }
            if(event.mouseButton.button == sf::Mouse::Right)
            {
                mouse.clicked_right = 1;
            }
        }
        if (event.type == sf::Event::TextEntered)
        {
            char letter = event.text.unicode;
            if(int(letter) >= 33 && int(letter) <= 125)
            {
                testUsunac +=event.text.unicode;
                std::cout<<testUsunac<<std::endl;
            }
            if(int(letter) == 8)
            {
                if(testUsunac.size() > 0)
                {
                    testUsunac = testUsunac.substr(0, testUsunac.size()-1);
                    std::cout<<testUsunac<<std::endl;
                }
            }

        }
    }

    for(unsigned int i=0; i<gameObjects.size();)
    {
        if(gameObjects[i]->getId() >= Textures::Id::flower1 &&  gameObjects[i]->getId() <= Textures::Id::trush_last)
        {
            if(gameObjects[i]->getGlobalBounds().contains(mousePosition.x, mousePosition.y))
            {
                mouse.thisFrameType = MouseAndCursor::Hand;
                if(mouse.clicked_left)
                {
                    if(gameObjects[i]->getId() >= Textures::Id::flower1 && gameObjects[i]->getId() <= Textures::Id::flower_last)
                    {
                        createObjects(1, 1);
                        timeResult += 2.0;
                    }
                    gameObjects.erase(gameObjects.begin()+i);
                }
                else
                {
                    i++;
                }
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }

    }

    mouse.setCursor();
}

void zbieranieSmieci::drawing()
{
    window->clear(sf::Color::Black);

    for(const auto &object: gameObjects)
    {
        object->drawing();
    }

    window->draw(textResultTime);

    window->display();
}
