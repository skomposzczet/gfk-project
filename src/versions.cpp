#include "versions.hpp"

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
        : Board(filename), current_black_x{_width - 1}, current_black_y{_height -1}
{   
    black_texture.loadFromFile("../img/black.png");
    _board.at(_height - 1).at(_width - 1) = Square(get_id(_height - 1, _width - 1), _height - 1, _width - 1, black_texture);
}

void Version2::_move(sf::Vector2i mouse_position)
{
    int x = mouse_position.x;
    int y = mouse_position.y;

    int x_b = dimension::margin + current_black_x * (dimension::size + dimension::gap) + dimension::size/2;
    int y_b = dimension::margin + current_black_y * (dimension::size + dimension::gap) + dimension::size/2;

    if(x >= dimension::margin && 
       x <= dimension::margin + _width * (dimension::size + dimension::gap) && 
       y >= dimension::margin && 
       y <= dimension::margin + _height * (dimension::size + dimension::gap)){

        // move right
        if(x <= x_b + dimension::size/2 + dimension::gap + dimension::size && 
           x >= x_b + dimension::size/2 + dimension::gap && 
           y <= y_b + dimension::size/2 && 
           y >= y_b - dimension::size/2)
            swap_squares(current_black_x, current_black_y, current_black_x++, current_black_y);

        // move left
        if(x >= x_b - dimension::size/2 - dimension::gap - dimension::size && 
           x <= x_b - dimension::size/2 - dimension::gap && 
           y <= y_b + dimension::size/2 && 
           y >= y_b - dimension::size/2)
            swap_squares(current_black_x, current_black_y, current_black_x--, current_black_y);

        // move down
        if(y <= y_b + dimension::size/2 + dimension::gap + dimension::size && 
           y >= y_b + dimension::size/2 + dimension::gap && 
           x <= x_b + dimension::size/2 && 
           x >= x_b - dimension::size/2)
            swap_squares(current_black_x, current_black_y, current_black_x, current_black_y++);

        // move up
        if(y >= y_b - dimension::size/2 - dimension::gap - dimension::size && 
           y <= y_b - dimension::size/2 - dimension::gap && 
           x <= x_b + dimension::size/2 && 
           x >= x_b - dimension::size/2)
            swap_squares(current_black_x, current_black_y, current_black_x, current_black_y--);

    }  
}

void Version2::scramble()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> r(0, 3);
    std::uniform_int_distribution<> Iterations(4,10);

    int size = Iterations(rng);

    for(int i=0; i < size; i++){

        int x_b = dimension::margin + current_black_x * (dimension::size + dimension::gap) + dimension::size/2;
        int y_b = dimension::margin + current_black_y * (dimension::size + dimension::gap) + dimension::size/2;

        int c = r(rng);

        std::cout << c << std::endl;

        if(c == 0)
            _move(sf::Vector2i(x_b + dimension::size, y_b));
        if(c == 1)
            _move(sf::Vector2i(x_b - dimension::size, y_b));
        if(c == 2)
            _move(sf::Vector2i(x_b, y_b + dimension::size));
        if(c == 3)
            _move(sf::Vector2i(x_b, y_b - dimension::size));
     
    }
}

void Version2::swap_squares(int x1, int y1, int x2, int y2){
    _board.at(y1).at(x1).change_position(y2, x2);
    _board.at(y2).at(x2).change_position(y1, x1);

    auto tmp = _board.at(y1).at(x1);
    _board.at(y1).at(x1) = _board.at(y2).at(x2);
    _board.at(y2).at(x2) = tmp;
}