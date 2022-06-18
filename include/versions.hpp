#ifndef VERSIONS_H_
#define VERSIONS_H_
#include "board.hpp"

class Version1: public Board
{
public:
    Version1(const std::string& filename);

    void _move(sf::Vector2i mouse_position) override;

    void scramble() override;

    bool solved() const override;

};

class Version2: public Board
{
public:
    Version2(const std::string& filename);

    void _move(sf::Vector2i mouse_position) override;

    void scramble() override;

    bool solved() const override;

private:
};

#endif // VERSIONS_H_