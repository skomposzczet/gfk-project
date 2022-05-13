#include "board.hpp"

Board::Board(const std::string& filename, const unsigned height, const unsigned width)
    : _height{height}, _width{width}
{
    if(!_texture.loadFromFile(filename))
    {
        std::cerr << "Could not find image with path: \"" << filename << "\"\n";
        exit(1);
    }

    _board.reserve(_height);
    for(unsigned i = 0 ; i < _height ; ++i)
    {
        std::vector<Square> temp;
        temp.reserve(_width);
        for(unsigned j = 0 ; j < _width ; ++j)
            temp.emplace_back(Square(get_id(i, j), i, j, _texture));

        _board.emplace_back(temp);
    }
}