#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include "square.hpp"

class Board: public sf::Drawable
{
public:
    Board(const unsigned height = 5, const unsigned width = 6);

protected:

private:
    const unsigned _height;
    const unsigned _width;
    std::vector<std::vector<Square>> _board;

    /**
     * @returns index based on given position indexes 
     */
    unsigned get_index(const unsigned i, const unsigned j) const { return i*_width + j; }
};

#endif // BOARD_H_