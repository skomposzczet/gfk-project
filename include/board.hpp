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

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        for(unsigned i = 0 ; i < _height ; ++i)
            for(unsigned j = 0 ; j < _width ; ++j)
                target.draw(_board.at(i).at(j));
    }

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