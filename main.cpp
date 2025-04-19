// Include system libraries
#include <iostream>

// Include SFML libraries
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Include my headers
#include "src/Utilities.h"
#include "src/Grid/Grid.hpp"
#include "src/MobQueue/MobQueue.h"
#include "src/Grid/GridTile.hpp"


// Needed to maximize the screen on launch
#include <Windows.h>

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
    sf::Texture grass(ASSETS_PATH "/images/grassTile.png",false, sf::IntRect({ 0,0 },
        { 67,120}));
    //sf::Texture t(ASSETS_PATH "/images/8_bit_pixel_dragon_by_elpixelboy_d87udq0-fullview.jpg");
    sf::Texture t(ASSETS_PATH "/images/default.png");
    sf::Sprite sprite(t);
    //t.loadFromFile(ASSETS_PATH "/images/8_bit_pixel_dragon_by_elpixelboy_d87udq0 - fullview.jpg");
    // ("assets/images/Jacob_Parnell_(LeKOBE)_the_kingdom_of_God_1ec41887-eaea-4609-922d-d2d0b6e5e0c9.png");
    
    GridTile* gameBoard[ROW][COLUMN] = { {nullptr} };

    
    // loop to declare grid tiles
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            //declare with texture
           gameBoard[i][j] = new GridTile(sf::Vector2f(j*window.getSize().x/12 + window.getSize().x/4, i * window.getSize().y / 5),
               sf::Vector2f(window.getSize().x / 10,window.getSize().x / 10), grass);
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

            //sf::Mouse::Button::Left
        }

        // Clear screen
        window.clear();

        //get clock time for mob queue
        

        //will spawn every ten seconds
        if (clk.getElapsedTime().asMilliseconds() % 10000 == 0) {
            //mobs.getMachineType();
        }

        
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COLUMN; j++) {
                // we need overloaded assignment operator
                //declare with texture?
                window.draw(*gameBoard[i][j]);
            }
        }

        //Draw 'Machine'
        //window.draw(m);
        //window.draw(m2);
        // 
        
        //m.move(sf::Vector2f(-.01,0));
        //m2.move(sf::Vector2f(-.02, 0));

        // Update the window
        window.display();
    }
}