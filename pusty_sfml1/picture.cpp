#include "picture.h"

Picture::Picture(const sf::Texture *texture, sf::RenderWindow *window_, int x, int y, int w, int h,
                 Textures::Id id_, bool visible_)
{
    static int index_ = 0;
    index = index_;
    index_++;

    window = window_;

    setTexture(*texture);

    setPosition(x, y);
    setSize(w, h);

    id = id_;

    visible = visible_;
    rotation = Rotation::Right;
}

void Picture::setIdAndTexture(Textures::Id id_, const sf::Texture *texture)
{
    id = id_;
    setTexture(*texture);
}

void Picture::drawing()
{
    if(visible)
    {
        window->draw(*this);
    }
}

void Picture::setSize(int w, int h)
{
    setScale(static_cast<float>(w)/getTextureRect().width, static_cast<float>(h)/getTextureRect().height);
}

void Picture::setRotation(Rotation rotation_)
{
    rotation = rotation_;
    setRotation(static_cast<float>(rotation_));
}

Picture::Rotation Picture::getRotation()
{
    return rotation;
}

bool Picture::getVisible()
{
    return visible;
}

Textures::Id Picture::getId()
{
    return id;
}

int Picture::getIndex()
{
    return index;
}

void Picture::rotate(float rotation_)
{
    setRotation(sf::Sprite::getRotation()+rotation_);
}

void Picture::setRotation(float rotation_)
{
    if(rotation_ != sf::Sprite::getRotation())
    {
        float h = getTextureRect().height*getScale().y;
        float w = getTextureRect().width*getScale().x;
        float half_diagonal = sqrt(w*w + h*h)/2;
        float diagonal_angle = atan(h/w);

        auto deg2rad = [](float angle){return angle*M_PI/180;};

        //kompensacja obrotu (obrot wzgledem punktu 0,0 a ma byc wzgledem srodka)
        float change_x = half_diagonal*(cos(deg2rad(sf::Sprite::getRotation())+diagonal_angle)
                                        - cos(deg2rad(rotation_)+diagonal_angle));
        float change_y = half_diagonal*(sin(deg2rad(sf::Sprite::getRotation())+diagonal_angle)
                                        - sin(deg2rad(rotation_)+diagonal_angle));

        move(change_x, change_y);
        sf::Sprite::setRotation(rotation_);
    }

}
