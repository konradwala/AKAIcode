#include "mouseandcursor.h"

MouseAndCursor::MouseAndCursor(sf::RenderWindow *window_)
{
    clicked_left = 0;
    clicked_right = 0;
    loadFromSystem(sf::Cursor::Arrow);
    actualType = Type::Arrow;
    thisFrameType = Type::Arrow;
    window = window_;
}

void MouseAndCursor::setCursor()
{
    if(actualType != thisFrameType)
    {
        loadFromSystem(thisFrameType);
        actualType = thisFrameType;
        window->setMouseCursor(*this);
    }

}
