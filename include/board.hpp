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

    void switch_mode()
    {
        mode = ( mode == Mode::normal ? Mode::preview : Mode::normal );
    }

protected:

private:
    const unsigned _height;
    const unsigned _width;
    std::vector<std::vector<Square>> _board;

    sf::Texture _texture;
    sf::RenderTexture _render_texture;
    sf::Sprite _sprite;

    enum class Mode {normal, preview};
    Mode mode = Mode::normal; 

    /**
     * @returns id based on given position indexes 
     */
    int get_id(const unsigned i, const unsigned j) const { return i*_width + j; }
};

#endif // BOARD_H_