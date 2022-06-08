#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <utility>
#include <algorithm>
#include <vector>

#include "board.hpp"
#include "dummy.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1185, 1000), L"OBRAZKOWE UKŁADANKI", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(sf::Vector2i(40, 40));
    window.setFramerateLimit(30);
    sf::Event event;
    sf::Color color = sf::Color::Black;

    std::string test_img{"../img/img1.png"};
    Board* board = new Dummy(test_img);

    while (window.isOpen())
    {
        window.clear(color);

        sf::Text text;
        sf::Font font;
        font.loadFromFile("../img/OpenSans-Bold.ttf");
        text.setFont(font);
        text.setCharacterSize(20); 
        text.setFillColor(sf::Color::White);
        text.setPosition(100,925);
        text.setString("1 - wersja z zamienianiem, 2 - wersja z przesuwaniem");
        window.draw(text);

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
                    board->setMode(event.key.code);
                }
            }

            if(board->getMode()==1){
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
                    int sizeAndMargin = dimension::size + dimension::margin;
                    int sizeMarginAndGap = dimension::size + dimension::margin + dimension::gap;
                    int sizeAndGap = dimension::size + dimension::gap;
                    int marginAndGap = dimension::margin + dimension::gap;
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    for(int i=0; i<board->getHeight(); i++){
                        for(int j=0; j<board->getWidth()-1; j++){
                            if(x >= sizeAndMargin + i * sizeAndGap && x <= sizeMarginAndGap + i * sizeAndGap && y >= dimension::margin + j * sizeAndGap && y <= sizeAndMargin + j * sizeAndGap){
                               board->scramble(j,i,1);
                            }
                        }
                    }

                    for(int i=0; i<=board->getHeight(); i++){
                        for(int j=0; j<board->getWidth()-2; j++){
                            if(x >= dimension::margin + i * sizeAndGap && x <= sizeAndMargin + i * sizeAndGap && y>= sizeAndMargin + j * sizeAndGap && y <= sizeMarginAndGap + j * sizeAndGap){
                                board->scramble(j,i,0);
                            }
                        }
                    }
                }
            }
        }
        window.draw(*board);
        window.display();
    }

    delete board;
}