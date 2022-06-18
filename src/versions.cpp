#include "versions.hpp"
#include <iostream>

Version1::Version1(const std::string& filename)
        : Board(filename)
{}

void Version1::_move(sf::Vector2i mouse_position)
{
    int sizeAndMargin = dimension::size + dimension::margin;
    int sizeMarginAndGap = dimension::size + dimension::margin + dimension::gap;
    int sizeAndGap = dimension::size + dimension::gap;
    int marginAndGap = dimension::margin + dimension::gap;
    int x = mouse_position.x;
    int y = mouse_position.y;
    for(int i=0; i<_height; i++){
        for(int j=0; j<_width-1; j++){
            if(x >= sizeAndMargin + i * sizeAndGap && x <= sizeMarginAndGap + i * sizeAndGap && y >= dimension::margin + j * sizeAndGap && y <= sizeAndMargin + j * sizeAndGap){
            _board.at(j).at(i).change_position(j, i+1);
            _board.at(j).at(i+1).change_position(j, i);

            auto temp = _board.at(j).at(i);
            _board.at(j).at(i) = _board.at(j).at(i+1);
            _board.at(j).at(i+1) = temp;

            _board.at(j).at(i).flip_vertical();
            _board.at(j).at(i+1).flip_vertical();   
            }   
        }
    }

    for(int i=0; i<=_height; i++){
        for(int j=0; j<_width-2; j++){
            if(x >= dimension::margin + i * sizeAndGap && x <= sizeAndMargin + i * sizeAndGap && y>= sizeAndMargin + j * sizeAndGap && y <= sizeMarginAndGap + j * sizeAndGap){
                _board.at(j).at(i).change_position(j+1, i);
                _board.at(j+1).at(i).change_position(j, i);

                auto temp = _board.at(j).at(i);
                _board.at(j).at(i) = _board.at(j+1).at(i);
                _board.at(j+1).at(i) = temp;

                _board.at(j).at(i).flip_horizontal();
                _board.at(j+1).at(i).flip_horizontal();
            }
        }
    }
}

void Version1::scramble()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distHeight(0,_height-1);
    std::uniform_int_distribution<std::mt19937::result_type> distHeight2(0,_height-2);
    std::uniform_int_distribution<std::mt19937::result_type> distWidth(0,_width-2);
    std::uniform_int_distribution<std::mt19937::result_type> distWidth2(0,_width-1);
    std::uniform_int_distribution<std::mt19937::result_type> Iterations(1,5);
    int sizeAndMargin = dimension::size + dimension::margin;
    int sizeMarginAndGap = dimension::size + dimension::margin + dimension::gap;
    int sizeAndGap = dimension::size + dimension::gap;
    int marginAndGap = dimension::margin + dimension::gap;
                
    for(int i=0; i<Iterations(rng); i++){
        _move(sf::Vector2i(dimension::margin + distHeight(rng)*sizeAndGap , sizeAndMargin + distWidth(rng) * sizeAndGap));
    }
}

Version2::Version2(const std::string& filename)
        : Board(filename)
{   
    black_texture.loadFromFile("../img/black.png");
    _board.at(_height - 1).at(_width - 1) = Square(get_id(_height - 1, _width - 1), _height - 1, _width - 1, black_texture);
}

void Version2::_move(sf::Vector2i mouse_position)
{
    int sizeAndMargin = dimension::size + dimension::margin;
    int sizeMarginAndGap = dimension::size + dimension::margin + dimension::gap;
    int sizeAndGap = dimension::size + dimension::gap;
    int marginAndGap = dimension::margin + dimension::gap;
    int x = mouse_position.x;
    int y = mouse_position.y;
    for(int i=0; i<_height; i++){
        for(int j=0; j<_width-1; j++){
            if(x >= sizeAndMargin + i * sizeAndGap && x <= sizeMarginAndGap + i * sizeAndGap && y >= dimension::margin + j * sizeAndGap && y <= sizeAndMargin + j * sizeAndGap){
            _board.at(j).at(i).change_position(j, i+1);
            _board.at(j).at(i+1).change_position(j, i);

            auto temp = _board.at(j).at(i);
            _board.at(j).at(i) = _board.at(j).at(i+1);
            _board.at(j).at(i+1) = temp;

            _board.at(j).at(i).flip_vertical();
            _board.at(j).at(i+1).flip_vertical();   
            }   
        }
    }

    for(int i=0; i<=_height; i++){
        for(int j=0; j<_width-2; j++){
            if(x >= dimension::margin + i * sizeAndGap && x <= sizeAndMargin + i * sizeAndGap && y>= sizeAndMargin + j * sizeAndGap && y <= sizeMarginAndGap + j * sizeAndGap){
                _board.at(j).at(i).change_position(j+1, i);
                _board.at(j+1).at(i).change_position(j, i);

                auto temp = _board.at(j).at(i);
                _board.at(j).at(i) = _board.at(j+1).at(i);
                _board.at(j+1).at(i) = temp;

                _board.at(j).at(i).flip_horizontal();
                _board.at(j+1).at(i).flip_horizontal();
            }
        }
    }
}

void Version2::scramble()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distHeight(0,_height-1);
    std::uniform_int_distribution<std::mt19937::result_type> distHeight2(0,_height-2);
    std::uniform_int_distribution<std::mt19937::result_type> distWidth(0,_width-2);
    std::uniform_int_distribution<std::mt19937::result_type> distWidth2(0,_width-1);
    std::uniform_int_distribution<std::mt19937::result_type> Iterations(1,5);
    int sizeAndMargin = dimension::size + dimension::margin;
    int sizeMarginAndGap = dimension::size + dimension::margin + dimension::gap;
    int sizeAndGap = dimension::size + dimension::gap;
    int marginAndGap = dimension::margin + dimension::gap;
                
    for(int i=0; i<Iterations(rng); i++){
        _move(sf::Vector2i(dimension::margin + distHeight(rng)*sizeAndGap , sizeAndMargin + distWidth(rng) * sizeAndGap));
    }
}