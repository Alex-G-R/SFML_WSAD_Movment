#include <iostream>

#include <Graphics.hpp>
#include <System.hpp>
#include <Window.hpp>
#include <Audio.hpp>
#include <Network.hpp>

void Update(sf::RectangleShape &player);
void Draw(sf::RenderWindow &window, sf::RectangleShape &player);

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Works!", sf::Style::Default);
    window.setFramerateLimit(120);

    sf::RectangleShape player;
    player.setSize(sf::Vector2f(80.f, 80.f));
    player.setPosition(sf::Vector2f(1920.f/2.f - player.getSize().x/2.f, 1080.f/2.f - player.getSize().y/2.f));


    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        Update(player);
        Draw(window, player);
    }

    return 0;
}

void Update(sf::RectangleShape &player)
{
    /* WSAD movment */
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player.getPosition().y > 0)
        player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y - 2.f));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player.getPosition().y < 1080 - player.getSize().y)
        player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y + 2.f));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player.getPosition().x > 0)
        player.setPosition(sf::Vector2f(player.getPosition().x - 2.f, player.getPosition().y));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player.getPosition().x < 1920 - player.getSize().x)
        player.setPosition(sf::Vector2f(player.getPosition().x + 2.f, player.getPosition().y));

    /* Color selection */
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        player.setFillColor(sf::Color::White);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        player.setFillColor(sf::Color::Red);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        player.setFillColor(sf::Color::Green);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
        player.setFillColor(sf::Color::Blue);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
        player.setFillColor(sf::Color::Magenta);

}

void Draw(sf::RenderWindow &window, sf::RectangleShape &player)
{
    window.clear();

    // Draw stuff
    window.draw(player);

    window.display();
}

