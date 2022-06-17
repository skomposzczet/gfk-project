#include "dummy.hpp"

Dummy::Dummy(const std::string& filename)
        : Board(filename)
    {}

void Dummy::_move(sf::Vector2i mouse_position)
    {}

void Dummy::scramble(int i, int j, int mode)
{
    if(mode){
        _board.at(i).at(j).change_position(i, j+1);
        _board.at(i).at(j+1).change_position(i, j);

        auto temp = _board.at(i).at(j);
        _board.at(i).at(j) = _board.at(i).at(j+1);
        _board.at(i).at(j+1) = temp;

        _board.at(i).at(j).flip_vertical();
        _board.at(i).at(j+1).flip_vertical();
    }
    else{
        _board.at(i).at(j).change_position(i+1, j);
        _board.at(i+1).at(j).change_position(i, j);

        auto temp = _board.at(i).at(j);
        _board.at(i).at(j) = _board.at(i+1).at(j);
        _board.at(i+1).at(j) = temp;

        _board.at(i).at(j).flip_horizontal();
        _board.at(i+1).at(j).flip_horizontal();
    }
}

bool Dummy::solved() const
{
    for(unsigned i = 0 ; i < _height ; ++i)
        for(unsigned j = 0 ; j < _width ; ++j)
            if (get_id(i, j) != _board.at(i).at(j).check())
                return false;

    return true;
}
