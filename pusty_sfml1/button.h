#ifndef button_h
#define button_h

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>


class Instruction;

class Button : public sf::RectangleShape
{
    sf::RenderWindow *window;
    sf::Text text;
    sf::RectangleShape border;
private:
    void (Instruction::*function_pointer)();

public:

    Button(int x, int y, int w, int h, const wchar_t text_[], const sf::Font *font, int characterSize,
           void (Instruction::*function_pointer_)(), sf::RenderWindow *window_);
    ~Button(){};
    void drawing();
    auto getFunction() -> void (Instruction::*)();
};

#endif
