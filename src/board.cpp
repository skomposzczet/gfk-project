#include "board.hpp"

Board::Board(const std::string& filename, const unsigned height, const unsigned width)
    : _height{height}, _width{width}
{
    if(!_texture.loadFromFile(filename))
    {
        std::cerr << "Could not find image with path: \"" << filename << "\"\n";
        exit(1);
    }

    _render_texture.create(1185, 1000);
    _render_texture.clear(sf::Color::Black);

    _sprite.setTexture(_render_texture.getTexture());
    _sprite.setPosition(sf::Vector2f(.0f, .0f));

    _board.reserve(_height);
    for(unsigned i = 0 ; i < _height ; ++i)
    {
        std::vector<Square> temp;
        temp.reserve(_width);
        for(unsigned j = 0 ; j < _width ; ++j)
        {
            temp.emplace_back(Square(get_id(i, j), i, j, _texture));
            _render_texture.draw(temp.at(j));
        }

        _board.emplace_back(temp);
    }

    _render_texture.display();
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (mode == Mode::normal)
    {
        for(unsigned i = 0 ; i < _height ; ++i)
            for(unsigned j = 0 ; j < _width ; ++j)
                target.draw(_board.at(i).at(j));
    }
    else if (mode == Mode::preview)
    {
        target.draw(_sprite);
    }
}

bool Board::solved() const
{
    for(unsigned i = 0 ; i < _height ; ++i)
        for(unsigned j = 0 ; j < _width ; ++j)
            if (get_id(i, j) != _board.at(i).at(j).id())
                return false;

    return true;
}

void Board::setModeOfGame(sf::Keyboard::Key toSet){
    if(toSet==sf::Keyboard::Num1){
        modeOfGame=1;
    }
    else if(toSet==sf::Keyboard::Num2){
        modeOfGame=2;
    }
}