#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <string>
#include <iostream>
#include "square.hpp"

class Board: public sf::Drawable
{
public:
    /**
     * @param filename path to image for texture 
     */
    Board(const std::string& filename, const unsigned height = 5, const unsigned width = 6);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    /**
     * @brief Switches between normal and preview mode
     */
    void switch_mode()
    {
        mode = ( mode == Mode::normal ? Mode::preview : Mode::normal );
    }

    /**
     * @returns true if game is solved, false otherwise
     */
    virtual bool solved() const;

    /**
     * @brief If game is in normal mode calls actual move function, doesnt do anything in preview mode 
     * 
     * @param mouse_position Click position
     */
    void move(sf::Vector2i mouse_position)
    {
        if (mode == Mode::normal)
            _move(mouse_position);
    }

protected:
    const unsigned _height;
    const unsigned _width;
    std::vector<std::vector<Square>> _board;

    virtual void _move(sf::Vector2i mouse_position) = 0; // internal implementation of move

    /**
     * @returns id based on given position indexes 
     */
    int get_id(const unsigned i, const unsigned j) const { return i*_width + j; }

private:
    sf::Texture _texture;
    sf::RenderTexture _render_texture;
    sf::Sprite _sprite;

    enum class Mode {normal, preview};
    Mode mode = Mode::normal; 
};

#endif // BOARD_H_