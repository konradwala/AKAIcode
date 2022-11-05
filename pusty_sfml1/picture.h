#ifndef picture_h
#define picture_h

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <math.h>
#include "textures.h"

class Picture : public sf::Sprite
{
public:
    enum class Rotation{Right=0, Down=90, Left=180, Up=270};
protected:
    sf::RenderWindow *window;
    bool visible;
    Rotation rotation;
    Textures::Id id;
    int index;

public:
    Picture(const sf::Texture *texture, sf::RenderWindow *window_, int x, int y, int w, int h,
            Textures::Id id_, bool visible_ = 1);
    ~Picture(){};

    void setIdAndTexture(Textures::Id id_, const sf::Texture *texture);
    void drawing();
    void setSize(int w, int h);
    void setRotation(Rotation rotation_);
    Rotation getRotation();
    bool getVisible();
    Textures::Id getId();
    int getIndex();
private:
    void rotate(float rotation);
    void setRotation(float rotation);
};

#endif
