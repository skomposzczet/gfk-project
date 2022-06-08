#include "dummy.hpp"

Dummy::Dummy(const std::string& filename)
        : Board(filename)
    {}

void Dummy::_move(sf::Vector2i mouse_position)
    {}

void Dummy::scramble(int i, int j, int mode)
{
    if(mode){
        // _board.at(i).at(j).change_position(i, j+1);
        // _board.at(i).at(j+1).change_position(i, j);
        // std::swap(_board.at(i).at(j), _board.at(i).at(j+1));

        _board.at(i).at(j).flip_vertical();
        _board.at(i).at(j+1).flip_vertical();
    }
    else{
        // _board.at(i).at(j).change_position(i+1, j);
        // _board.at(i+1).at(j).change_position(i, j);

        _board.at(i).at(j).flip_horizontal();
        _board.at(i+1).at(j).flip_horizontal();
    }
}

void Dummy::setMode(sf::Keyboard::Key toSet){
    if(toSet==sf::Keyboard::Num1){
        mode=1;
    }
    else if(toSet==sf::Keyboard::Num2){
        mode=2;
    }
}

int Dummy::getMode()const{
    return mode;
}