#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>

#include "versions.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1185, 1000), L"OBRAZKOWE UKŁADANKI", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(sf::Vector2i(40, 40));
    window.setFramerateLimit(30);
    sf::Event event;
    sf::Color color = sf::Color::Black;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> numberOfImage(1,4);
    std::string path = "../img/img" + std::to_string(numberOfImage(rng)) + ".png";
    std::string test_img{path};

    sf::Text text;
    sf::Font font;
    font.loadFromFile("../img/OpenSans-Bold.ttf");
    text.setFont(font);
    text.setCharacterSize(20); 
    text.setFillColor(sf::Color::White);
    text.setPosition(100,925);
    text.setString("1 - wersja z zamienianiem, 2 - wersja z przesuwaniem");

    Board* board = new Dummy(test_img);

    while (window.isOpen())
    {
        window.clear(color);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                window.close();

            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Tab){
                    board->switch_mode();
                }

                if (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Num2){
                    board->setGameMode(event.key.code);
                    board->scramble();
                }
                
                if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
                    board->move(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                }
            }
            
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
            board->move(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
        }
        if (board->getGameMode() != 0)
            if(board->solved())
                window.close();
        }

        window.draw(text);
        window.draw(*board);
        window.display();
    }

    delete board;

}