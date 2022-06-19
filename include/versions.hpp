#ifndef VERSIONS_H_
#define VERSIONS_H_

#include "board.hpp"

enum class Game_version {None, First, Secund};

class Version1: public Board
{
public:
    /**
     * @param filename path to image for texture 
     */
    Version1(const std::string& filename);

    /**
     * @brief scrambles puzzles at the beginning of the game
     */
    void scramble() override;

protected:
    /**
     * @brief implementation of move
     * 
     * @param mouse_position position of the click
     */
    void _move(sf::Vector2i mouse_position) override;
};

class Version2: public Board
{
public:
    /**
     * @param filename path to image for texture 
     */
    Version2(const std::string& filename);

    /**
     * @brief scrambles puzzles at the beginning of the game
     */
    void scramble() override;

protected:
    /**
     * @brief implementation of move
     * 
     * @param mouse_position position of the click
     */
    void _move(sf::Vector2i mouse_position) override;

private:
    sf::Texture black_texture;
    unsigned current_black_x;
    unsigned current_black_y;

    /**
     * @brief Helper function for moving squares
     * 
     * @param x1 x index of first square
     * @param y1 y index of first square
     * @param x2 x index of secund square
     * @param y2 y index of secund square
     */
    void swap_squares(int x1, int y1, int x2, int y2);
};

#endif // VERSIONS_H_