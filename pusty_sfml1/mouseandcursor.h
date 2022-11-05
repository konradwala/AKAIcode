#ifndef mouseandcursor_h
#define mouseandcursor_h

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

class MouseAndCursor : public sf::Mouse, public sf::Cursor
{
    sf::RenderWindow *window;
    Type actualType;

public:
    bool clicked_left;
    bool clicked_right;
    Type thisFrameType;
    MouseAndCursor(sf::RenderWindow *window_);
    ~MouseAndCursor(){};
    void setCursor();

};

#endif
