#include "button.h"

Button::Button(int x, int y, int w, int h, const wchar_t text_[], const sf::Font *font, int characterSize,
               void (Instruction::*function_pointer_)(), sf::RenderWindow *window_)
       :text(text_, *font, characterSize)
{
    setSize({static_cast<float>(w), static_cast<float>(h)});
    setPosition(x, y);
    setFillColor({169, 169, 169});

    border.setSize({static_cast<float>(w-4), static_cast<float>(h-4)});
    border.setPosition(x+2, y+2);
    border.setFillColor({169, 169, 169});
    border.setOutlineColor({105, 105, 105});
    border.setOutlineThickness(1);

    function_pointer = function_pointer_;

    window = window_;

    sf::FloatRect rectText = text.getLocalBounds();
    text.setPosition(x+(w-rectText.width)/2, y+(h-characterSize)/2);
    text.setFillColor({0, 0, 0});
}

void Button::drawing()
{
    window->draw(*this);
    window->draw(border);
    window->draw(text);
}

auto Button::getFunction() -> void (Instruction::*)()
{
    return function_pointer;
}
