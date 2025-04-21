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
   

    /*MobQueue mobs;
    mobs.loadFromLevelFile("../MobList/LevelOne.csv");*/

    //test machines


    //grass texture
    sf::Texture grass(ASSETS_PATH "/images/grassTile.png",false, sf::IntRect({ 0,0 },
        { 67,120}));

    //test texture
    sf::Texture t(ASSETS_PATH "/images/grassTile.png",false, sf::IntRect({ 0,0 },
        { 67,120 }));
    sf::Sprite * sprite = new sf::Sprite(t);
    (*sprite).setColor(sf::Color::Transparent);
    
    GridTile* gameBoard[ROW][COLUMN] = { {nullptr} };

    
    // loop to declare grid tiles
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            //declare with texture
           gameBoard[i][j] = new GridTile(sf::Vector2f(j*window.getSize().x/12 + window.getSize().x/4, i * window.getSize().y / 5),
               sf::Vector2f(window.getSize().x / 10,window.getSize().x / 10), grass);
        }
    }


    //vector of sprites
    //will change to tower type
    vector<sf::Sprite> towerVector;

    

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (event->is<sf::Event::MouseButtonPressed>()) {
                std::cout << "clicking mouse" << std::endl;

            }

            
        }

        // Clear screen
        window.clear();

        //get clock time for mob queue
        

        //will spawn every ten seconds
        if (clk.getElapsedTime().asMilliseconds() % 10000 == 0) {
            //mobs.getMachineType();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            for (int i = 0; i < ROW; i++) {
                for (int j = 0; j < COLUMN; j++) {
                    // we need overloaded assignment operator
                    //declare with texture?
                    if ((*gameBoard[i][j]).getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition().x,
                        sf::Mouse::getPosition().y))) {
                        //sprite.setPosition(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
                        sprite = new sf::Sprite(t);
                        (*sprite).setPosition({ (*gameBoard[i][j]).getPosition().x, (*gameBoard[i][j]).getPosition().y });
                        (*sprite).setColor(sf::Color::Magenta);
                        towerVector.push_back(*sprite);

                       
                    }
                }
            }
           
           
        }


       
        
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COLUMN; j++) {
                // we need overloaded assignment operator
                //declare with texture?
                window.draw(*gameBoard[i][j]);
            }
        }
        for (int i = 0; i < towerVector.size(); i++) {
            window.draw(towerVector.at(i));
        }

        // Update the window
        window.display();
    }
}