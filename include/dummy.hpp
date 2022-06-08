#pragma once
#include "board.hpp"

class Dummy: public Board
{
public:
    Dummy(const std::string& filename);

    void _move(sf::Vector2i mouse_position) override;

    void scramble(int i, int j, int mode) override;


    int getMode()const;

private:
};