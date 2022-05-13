#include "square.hpp"

Square::Square(const int id, const unsigned i, const unsigned j, sf::Texture& texture)
    : _id{id}
{
    auto ground_zero = get_ground_zero(i, j);
    _sprite.setTexture(texture);
    _sprite.setTextureRect(sf::IntRect(ground_zero.x, ground_zero.y, dimension::size, dimension::size));

    auto position = get_position(i, j);
    _sprite.setPosition(position);

    _sprite.setOrigin(dimension::size/2, dimension::size/2);
}