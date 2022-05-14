#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "board.hpp"

class Dummy: public Board
{
public:
    Dummy(const std::string& filename)
        : Board(filename)
    {}

    void _move(sf::Vector2i mouse_position) override
    {}

    void scramble() override
    {
        _board.at(1).at(1).change_position(1, 2);
        _board.at(1).at(2).change_position(1, 1);

        _board.at(1).at(1).flip_vertical();
        _board.at(1).at(2).flip_vertical();
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1185, 1000), L"OBRAZKOWE UKŁADANKI", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(sf::Vector2i(40, 40));
    window.setFramerateLimit(30);
    sf::Event event;
    sf::Color color = sf::Color::Black;

    std::string test_img{"../img/img1.png"};
    Board* board = new Dummy(test_img);
    board->scramble();

    while (window.isOpen())
    {
        window.clear(color);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                window.close();

            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Tab)
                    board->switch_mode();
            }
        }

        window.draw(*board);
        window.display();
    }

    delete board;
}