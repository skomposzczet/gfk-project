#ifndef SQUARE_H_
#define SQUARE_H_

#include <SFML/Graphics.hpp>

struct dimension
{
    enum 
    {   
        /** size of single square */
        size = 160,
        /** length of gap between squares */
        gap = 10, 
        /** top / left margin */
        margin = 50
    };
};

class Square: public sf::Drawable
{
public:
    Square(const int id, const unsigned i, const unsigned j, sf::Texture& texture)
        : _id{id}
    {
        auto ground_zero = get_ground_zero(i, j);
        _sprite.setTexture(texture);
        _sprite.setTextureRect(sf::IntRect(ground_zero.x, ground_zero.y, dimension::size, dimension::size));

        auto position = get_position(i, j);
        _sprite.setPosition(position);

        _sprite.setOrigin(dimension::size/2, dimension::size/2);

    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(_sprite);
    }

private:
    const int _id;

    sf::Sprite _sprite;

    /**
     * @param i x index of square
     * @param j y index of square
     * @returns Position of top left corner of desired part of texture based on squares indexes 
     */
    static sf::Vector2i get_ground_zero(const unsigned i, const unsigned j)
    {
        return sf::Vector2i(j * dimension::size, i * dimension::size);
    }

    /**
     * @param i x index of square
     * @param j y index of square
     * @return Position of square on the screen based on its indexes
     */
    static sf::Vector2f get_position(const unsigned i, const unsigned j)
    {
        return sf::Vector2f(static_cast<float>(dimension::margin) + j * (dimension::size + dimension::gap) + dimension::size/2, static_cast<float>(dimension::margin) + i * (dimension::size + dimension::gap) + dimension::size/2);
    }
};

#endif // SQUARE_H_