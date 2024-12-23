#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "src/binary_tree.h"
using sf::CircleShape;

int main(void)
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({900, 800}), "TXT-editor");
    window.setFramerateLimit(60);

    CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    float x = 10;
    float y = 30;
    sf::Vector2<float> pos(x, y);
    circle.setPosition(pos);
    // this is the root of our tree
    // Node<int> *root = new Node<int>(1);
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();

            // Draw a circle where I click
            if (event->is<sf::Event::MouseButtonPressed>())
            {
                sf::Vector2<float> mouse_pos(sf::Mouse::getPosition(window).x - 50, sf::Mouse::getPosition(window).y - 50);
                circle.setPosition(mouse_pos);
            }
        }

        window.clear();
        window.draw(circle);
        window.display();
    }
}