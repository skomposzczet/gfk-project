#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "board.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1185, 1000), L"OBRAZKOWE UKŁADANKI", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(sf::Vector2i(40, 40));
    window.setFramerateLimit(30);
    sf::Event event;
    sf::Color color = sf::Color::Black;

    while (window.isOpen())
    {
        window.clear(color);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                window.close();
        }

        window.display();
    }
}