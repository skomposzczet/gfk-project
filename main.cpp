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

    Board* board ;
    Game_version game_version = Game_version::None;

    while (window.isOpen())
    {
        window.clear(color);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                window.close();

            else if(event.type == sf::Event::KeyPressed)
            {
                if(game_version != Game_version::None){
                    if(event.key.code == sf::Keyboard::Tab){
                        board->switch_mode();
                    }
                }
                else {
                    if (event.key.code == sf::Keyboard::Num1){
                        board = new Version1(test_img);
                        game_version = Game_version::First;
                        board->scramble();
                    }

                    if ( event.key.code == sf::Keyboard::Num2){
                        board = new Version2(test_img);
                        game_version = Game_version::Secund;
                        board->scramble();
                    }
                }
            }
            
            if(game_version != Game_version::None)
                if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    board->move(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
        }
        
        if(game_version != Game_version::None) {
            if(board->solved())
                window.close();

            window.draw(*board);
        }
        else
            window.draw(text);
        
        window.display();
    }

    if(board != nullptr)
        delete board;

}