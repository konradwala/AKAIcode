#include "project.h"
#include <fstream>
#include <string>

Food::Food(string nick, RenderWindow *window)
{
    window->clear(sf::Color::Black);
    play(window, nick);
}

int Food::play(RenderWindow *window, string nick)
{
    Clock clock;
    Hero MyHero;
    float dt=0;
    float end_game_time=0;
    int points=0;

    vector<Item> vec;
    Item item;
    vec.push_back(item);

    sf::Sprite background;
    sf::Texture background_texture;
    if (!background_texture.loadFromFile("background.png")) {
        std::cerr << "Could not load texture background.png" << std::endl;
    }
    sf::Text Time;
    sf::Text points_text;
        sf::Font font;
        font.loadFromFile("OpenSansIT.ttf");
        Time.setFont(font);
        float time_exposing = 30-end_game_time;
        string time_left = "score: " + to_string(time_exposing);
        Time.setString(time_left);
        Time.setCharacterSize(50);
        Time.setFillColor(sf::Color::Red);
        Time.setOutlineThickness(1.5);
        Time.setOutlineColor(sf::Color::Green);
        Time.setStyle(sf::Text::Bold);
        Time.setPosition(670,25);

        points_text.setFont(font);
        string points_string = to_string(points);
        points_text.setString(points_string);
        points_text.setCharacterSize(35);
        points_text.setFillColor(sf::Color::Red);
        points_text.setOutlineThickness(1.5);
        points_text.setOutlineColor(sf::Color::Green);
        points_text.setStyle(sf::Text::Bold);
        points_text.setPosition(10,25);


    background.setPosition(0.f, 0.f);
    background.setScale(0.65, 0.75);
    background.setTexture(background_texture);



    while(window->isOpen())
    {
    if(end_game_time <= 30)
    {
        //CHECKING EVENTS
        Event event;
    while (window->pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            cout << "Closing Window" << endl;
            window->close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
        {
           MyHero.left_key(dt);
        }
        if(Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
        {
            MyHero.right_key(dt);
        }
    }
    end_game_time += clock.getElapsedTime().asSeconds();
    dt = clock.restart().asSeconds();
    float time_exposing = 30-end_game_time;
    string time_left =to_string(time_exposing);
    Time.setString(time_left);
    //LOGIC
    MyHero.moving();
    vec[0].item_move(dt);
    sf::FloatRect playerBounds=MyHero.getGlobalBounds();
    if(vec[0].hero_touch(playerBounds, points))
    {
        vec.pop_back();
        vec.emplace_back();
    }
    if(vec[0].fall(playerBounds, points))
    {
        vec.pop_back();
        vec.emplace_back();
    }
    points_string = "score: " + to_string(points);
    points_text.setString(points_string);

    clock.restart();

    window->clear(sf::Color::Black);
    window->draw(background);
    window->draw(Time);
    window->draw(points_text);
    window->draw(MyHero);
    for(auto &el:vec)
        window->draw(el);
    window->display();
    }
    else
    {
        //window->close();
        MyHero.saving_score(nick, points);
        return 1;
    }
    }
    return 0;
}




Hero::Hero()
{
    sf::Texture texture2;
    if (!texture2.loadFromFile("open_mouth.png")) {
        std::cerr << "Could not load texture open_mouth.png" << std::endl;
    }

    Herotexture = texture2;
    setOrigin(96.f, 128.f);
    setPosition(100.f, 500.f);
    setScale(0.3, 0.3);
    setTexture(Herotexture);
    rect_left=sf::IntRect(0, 0, 640, 640);
    rect_right=sf::IntRect(640, 0, -640, 640);
}

void Hero::moving()
{
    sf::FloatRect playerBounds=getGlobalBounds();


    nextPos = playerBounds;
    nextPos.left += velocity.x;
    if(getGlobalBounds().left + nextPos.left >0  &&  nextPos.left+nextPos.width<800)
    {
        move(velocity);
    }

}
void Hero::left_key(float time)
{
    velocity.x=0;
    velocity.x += -movementSpeed * time;
    setTextureRect(rect_left);
}

void Hero::right_key(float time)
{
    velocity.x=0;
    velocity.x += movementSpeed * time;
    setTextureRect(rect_right);
}

void Hero::saving_score(string nick, int points)
{
        std::ofstream myfile;
          fstream plik;
              plik.open("result.txt", ios::app);
              plik<<nick<<" "<<points<<endl;

              plik.close();
              plik.clear();
}

Item::Item()
{
    int number = rand()%(number_of_items+1);
    sf::Texture texture3;
    //number=6;
    if(number == 0)
      {
        if (!item_texture.loadFromFile("banana.png")) {
          std::cerr << "Could not load texture banana.jpg" << std::endl;
        }
        is_healthy=true;
        setScale(0.17, 0.17);
      }
    if(number == 1)
      {
        if (!item_texture.loadFromFile("coke.png")) {
          std::cerr << "Could not load texture coke.png" << std::endl;
        }
        is_healthy=false;
        setScale(0.5, 0.5);
      }
    if(number == 2)
      {
        if (!item_texture.loadFromFile("apple.png")) {
          std::cerr << "Could not load texture apple.png" << std::endl;
        }
        is_healthy=true;
        setScale(0.16, 0.16);
      }
    if(number == 3)
      {
        if (!item_texture.loadFromFile("pizza.png")) {
          std::cerr << "Could not load texture pizza.png" << std::endl;
        }
        is_healthy=false;
        setScale(0.35, 0.35);
      }
    if(number == 4)
      {
        if (!item_texture.loadFromFile("carrot.png")) {
          std::cerr << "Could not load texture carrot.png" << std::endl;
        }
        is_healthy=true;
        setScale(0.18, 0.18);
      }
    if(number == 5)
      {
        if (!item_texture.loadFromFile("hamburger.png")) {
          std::cerr << "Could not load texture hamburger.png" << std::endl;
        }
        is_healthy=false;
        setScale(0.18, 0.18);
      }
    if(number == 6)
      {
        if (!item_texture.loadFromFile("water.png")) {
          std::cerr << "Could not load texture water.png" << std::endl;
        }
        is_healthy=true;
        setScale(0.45, 0.45);
      }

      setTexture(item_texture);
//    setOrigin(96.f, 128.f);
      int x = rand()%(600);
      setPosition(x, -100.f);
}

void Item::item_move(float time)
{
    velocity.y += movementSpeed * time/2;
    move(velocity);
}

bool Item::hero_touch(sf::FloatRect rect, int &points)
{
    sf::FloatRect rect2 = getGlobalBounds();
    rect2.top -= 75;
    if(rect2.intersects(rect))
    {
        if(is_healthy) points+=1;
        else points-=1;
        return true;
    }
    return false;
}

bool Item::fall(sf::FloatRect rect, int &points)
{
    if(getGlobalBounds().top+getGlobalBounds().height > 660)
    {
        if(is_healthy) points--;
        else points++;
        return true;
    }
    return false;
}
