#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "versions.hpp"

int main()
{
    /// Setting up window
    sf::RenderWindow window(sf::VideoMode(1185, 1000), L"OBRAZKOWE UKŁADANKI", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(sf::Vector2i(40, 40));
    window.setFramerateLimit(30);
    sf::Event event;
    sf::Color color = sf::Color::Black;

    /// Choosing random image
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> numberOfImage(1,4);
    std::string path = "../img/img" + std::to_string(numberOfImage(rng)) + ".png";
    std::string test_img{path};


    /// Setting up menu text
    sf::Text text, title;
    sf::Font font;

    font.loadFromFile("../img/OpenSans-Bold.ttf");
    title.setFont(font);
    title.setCharacterSize(40);
    title.setFillColor(sf::Color::White);
    text.setFont(font);
    text.setCharacterSize(30); 
    text.setFillColor(sf::Color::White);

    title.setPosition(400, 400);
    text.setPosition(400, 460);
    title.setString(L"Wybór wersji:");
    text.setString("1 - wersja z zamienianiem \n2 - wersja z przesuwaniem");

    /// Setting up board and game version variables
    Board* board = nullptr;
    Game_version game_version = Game_version::None;

    while (window.isOpen())
    {
        window.clear(color);

        /// event handling
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                window.close();

            else if (event.type == sf::Event::KeyPressed)
            {
                if (game_version != Game_version::None){
                    if (event.key.code == sf::Keyboard::Tab){
                        board->switch_mode();
                    }
                }
                else {
                    if (event.key.code == sf::Keyboard::Num1){
                        board = new Version1(test_img);
                        game_version = Game_version::First;
                        board->scramble();
                    }

                    if (event.key.code == sf::Keyboard::Num2){
                        board = new Version2(test_img);
                        game_version = Game_version::Secund;
                        board->scramble();
                    }
                }
            }
            
            if (game_version != Game_version::None)
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                    board->move(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
        }
        
        /// drowing and chacking win conditions
        if (game_version != Game_version::None) {
            if(board->solved())
                window.close();

            window.draw(*board);
        }
        else {
            window.draw(title);
            window.draw(text);
        }
        
        /// displaying content on window
        window.display();
    }

    if(board != nullptr)
        delete board;

}