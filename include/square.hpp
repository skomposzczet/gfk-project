#ifndef SQUARE_H_
#define SQUARE_H_

#include <SFML/Graphics.hpp>

class Square: public sf::Drawable
{
public:
    Square(const int id)
        : _id{id}
    {}

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {}

private:
    const int _id;
};

#endif // SQUARE_H_