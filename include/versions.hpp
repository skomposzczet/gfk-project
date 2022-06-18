#ifndef VERSIONS_H_
#define VERSIONS_H_
#include "board.hpp"

enum class Game_version {None, First, Secund};

class Version1: public Board
{
public:
    Version1(const std::string& filename);

    void _move(sf::Vector2i mouse_position) override;

    void scramble() override;

};

class Version2: public Board
{
public:
    Version2(const std::string& filename);

    void _move(sf::Vector2i mouse_position) override;

    void scramble() override;

    sf::Texture black_texture;
private:
};

#endif // VERSIONS_H_