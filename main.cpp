// Include system libraries
#include <iostream>

// Include SFML libraries
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Include my headers
#include "src/Utilities.h"
#include "src/Machine.h"
#include "src/Grid/Grid.hpp"

// Modified code from SFML's website

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");

    // Create a graphical text to display
    const sf::Font font = Utilities::getAttributedFont(FontStyle::SemiBoldItalic, "SF-Pro");
    sf::Text text(font, "Humans v AI", 50);


    Machine m(sf::Vector2f(window.getSize().x/20,window.getSize().y/10),sf::Vector2f(window.getSize().x +100, window.getSize().y + 500));
    Machine m2(sf::Vector2f(window.getSize().x / 20, window.getSize().y / 10), sf::Vector2f(window.getSize().x + 100, window.getSize().y + 500));

    //figure out how to declare Grid
    //Grid gameBoard();

    sf::Keyboard::Key k(sf::Keyboard::Key::S);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        

        // Draw the string
        window.draw(text);
        window.draw(text2);

        //Draw 'Machine'
        window.draw(m);
        window.draw(m2);
        
        m.move(sf::Vector2f(.01,.01));
        m2.move(sf::Vector2f(.02, .01));

        // Update the window
        window.display();
    }
}