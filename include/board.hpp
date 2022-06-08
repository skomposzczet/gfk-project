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

    /**
     * @brief Scrambles two squares that are next to place where user clicked
     * 
     * @param i First coordinate of a left square
     * @param j Second coordinate of a left square
     * @param mode 0 flips horizontally, 1 flips vertically
     */
    virtual void scramble(int i, int j, int mode) = 0; // scrambling puzzle 


    /** @brief sets 1 for first vesrion of game and 2 for the second one*/
    virtual void setMode(sf::Keyboard::Key toSet)=0;

    virtual int getMode()const=0;

    /** @returns height of an inage*/
    unsigned getHeight()const{
        return _height;
    }

    /** @returns width of an inage*/
    unsigned getWidth()const{
        return _width;
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
     /** 1 - first mode, 2- second mode */
    int modeOfgame = 1;
};

#endif // BOARD_H_