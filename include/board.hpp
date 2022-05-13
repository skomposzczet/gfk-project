#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <string>
#include <iostream>
#include "square.hpp"

class Board: public sf::Drawable
{
public:
    Board(const std::string& filename, const unsigned height = 5, const unsigned width = 6);

protected:

private:
    const unsigned _height;
    const unsigned _width;
    std::vector<std::vector<Square>> _board;

    sf::Texture _texture;

    /**
     * @returns id based on given position indexes 
     */
    unsigned get_id(const unsigned i, const unsigned j) const { return i*_width + j; }
};

#endif // BOARD_H_