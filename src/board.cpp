#include "board.hpp"

Board::Board(const unsigned height, const unsigned width)
    : _height{height}, _width{width}
{
    _board.reserve(_height);
    for(unsigned i = 0 ; i < _height ; ++i)
    {
        std::vector<Square> temp;
        temp.reserve(_width);
        for(unsigned j = 0 ; j < _width ; ++j)
            temp.emplace_back(Square(get_index(i, j)));

        _board.emplace_back(temp);
    }
}