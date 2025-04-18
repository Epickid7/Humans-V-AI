// Include system libraries
#include <iostream>

// Include SFML libraries
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Include my headers
#include "src/Utilities.h"
#include "src/Grid/Grid.hpp"
#include "src/Machine.hpp"
#include "src/MobQueue/MobQueue.h"


// Needed to maximize the screen on launch
#include <Windows.h>

// Modified code from SFML's website

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");

    
    sf::Clock clk;
    //Maximize window??
    ::ShowWindow(window.getNativeHandle(), SW_MAXIMIZE);

    // Create a graphical text to display
    const sf::Font font = Utilities::getAttributedFont(FontStyle::SemiBoldItalic, "SF-Pro");
    sf::Text text(font, "Humans v AI", 50);

    /*MobQueue mobs;
    mobs.loadFromLevelFile("../MobList/LevelOne.csv");*/

    //test machines
    //Machine m(sf::Vector2f(window.getSize().x/20,window.getSize().y/10),sf::Vector2f(window.getSize().x +100, window.getSize().y/2));
    //Machine m2(sf::Vector2f(window.getSize().x / 20, window.getSize().y / 10), sf::Vector2f(window.getSize().x + 100, window.getSize().y/2));

    //test texture
    //sf::Texture t("assets/images/Jacob_Parnell_(LeKOBE)_the_kingdom_of_God_1ec41887-eaea-4609-922d-d2d0b6e5e0c9.png");
    
    //figure out how to declare Grid
    // loop to declare grid tiles
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {

        }
    }

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

        //get clock time for mob queue
        

        //will spawn every ten seconds
        if (clk.getElapsedTime().asMilliseconds() % 10000 == 0) {
            //mobs.getMachineType();
        }


        // Draw the string
        //window.draw(text);
        

        //Draw 'Machine'
        //window.draw(m);
        //window.draw(m2);
        
        //m.move(sf::Vector2f(-.01,0));
        //m2.move(sf::Vector2f(-.02, 0));

        // Update the window
        window.display();
    }
}