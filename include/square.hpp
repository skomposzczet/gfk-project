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
    /**
     * @param id id of square 
     * @param i x index of square
     * @param j y index of square
     * @param texture texture to be used on squares
     */
    Square(const int id, const unsigned i, const unsigned j, sf::Texture& texture);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(_sprite);
    }

    /**
     * @brief Sets new squares position
     * 
     * @param i x index of square
     * @param j y index of square
     */
    void change_position(const unsigned i, const unsigned j)
    {
        _sprite.setPosition(get_position(i, j));
    }

    /**
     * @brief Flips square vertically
     */
    void flip_vertical()
    {
        _sprite.scale(-1, 1);
        _flip_ver = !_flip_ver;
    }

    /**
     * @brief Flips square horizontally
     */
    void flip_horizontal()
    {
        _sprite.scale(1, -1);
        _flip_hor = !_flip_hor;
    }

    /**
     * @returns id of square if it is not flipped, negative value otherwise 
     */
    int check() const
    {
        return ( _flip_ver || _flip_hor ? -1 : _id );
    }

    /**
     * @returns id of square 
     */
    int id() const
    {
        return _id;
    }

private:
    const int _id;

    sf::Sprite _sprite;

    bool _flip_hor = false;
    bool _flip_ver = false;

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