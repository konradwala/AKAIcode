#include <iostream>
using namespace std;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Food
{
private:

public:
    Food(string nick, RenderWindow *window);
    int play(RenderWindow *window, string nick);
};


class Hero:public sf::Sprite
{
private:
    sf::Texture Herotexture;
    const float movementSpeed = 200.f;
    sf::Vector2f velocity;
    sf::FloatRect nextPos;
    sf::IntRect rect_left;
    sf::IntRect rect_right;
public:
    Hero();
    void moving();
    void left_key(float time);                                                    //controlling hero
    void right_key(float time);
    void saving_score(string nick, int points);
};

class Item:public sf::Sprite
{
private:
    const int number_of_items=6;
    sf::Texture item_texture;
    const float movementSpeed = 5.f;
    sf::Vector2f velocity;
    bool is_healthy;
public:
    Item();
    void item_move(float time);
    bool hero_touch(sf::FloatRect rect, int &points);
    bool fall(sf::FloatRect rect, int &points);
};

