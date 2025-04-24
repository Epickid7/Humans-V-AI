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
#include "src/TowerSelect/TowerSelect.h"
#include "src/Tower.h"
#include "src/Machine.h"
#include "src/machines/Terminator.hpp"


// Needed to maximize the screen on launch
#include <Windows.h>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");
    window.setVerticalSyncEnabled(true);
    //set mouse to window position
    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    
    sf::Clock clk;

    //Maximize window
    ::ShowWindow(window.getNativeHandle(), SW_MAXIMIZE);

    // Create a graphical text to display
    TowerSelect selectMenu;
   
    // Create Player object to store game data
    Player player(300);
    const sf::Font font = Utilities::getAttributedFont(FontStyle::Heavy, "SF-Pro");

    /*MobQueue mobs;
    mobs.loadFromLevelFile("../MobList/LevelOne.csv");*/


    //grass texture
    sf::Texture grass(ASSETS_PATH "/images/grassTile.png",false, sf::IntRect({ 0,0 },
        { 67,120}));


    sf::Texture bankTest(ASSETS_PATH "/images/bank.png");
    sf::Sprite s(bankTest);
    

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

    // entity vectors
    vector<sf::Sprite> towerVector; // sprites, switch to towers
    //vector<Tower> towerVector;
    vector<Machine> machineVector; // machines
    std::vector<Projectile> projectileVector; // projectiles

    Bank bank;
   
    sf::Music music(ASSETS_PATH "/music/Ultimate Battle.wav");
    music.setVolume(35.f);
    music.setPitch(1.2f);
    music.play();
    music.setLooping(true);
    sf::Music effect(ASSETS_PATH "/music/brick_grate.wav");
    effect.setPitch(0.6f);
    effect.play();
    sf::Music crunch(ASSETS_PATH "/music/cracker_munch.wav");
    crunch.setPitch(2.f);
    crunch.play();

    // test terminator
    Terminator terminator = Terminator(200, 200);

    // Start the game loop

    //clk.start();

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

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            for (int i = 0; i < ROW; i++) {
                for (int j = 0; j < COLUMN; j++) {
                    // we need overloaded assignment operator
                    //declare with texture?
                    
                    if ((*gameBoard[i][j]).getGlobalBounds().contains(sf::Vector2f(mouse.x,
                        mouse.y))) {

                        //test code for inserting tower
                       
                        //sprite.setPosition(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
                        sprite = new sf::Sprite(s);
                        (*sprite).setPosition({ (*gameBoard[i][j]).getPosition().x, (*gameBoard[i][j]).getPosition().y });
                        (*sprite).setColor(sf::Color::White);
                        towerVector.push_back(*sprite);
                        
                       
                    }
                }
            }
        }

        //Draw money
        sf::Text money(font, sf::String( std::to_string(player.getMoney())), 35);
        money.setPosition(sf::Vector2f(0, 0 ));
        window.draw(money);

        //draw menu for choosing tower
        selectMenu.displayTowerList(window);
        selectMenu.checkForTowerSelect();
        //check if user is clicking a tile

        //check if user has necessary funds for selected tower

        

        mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));


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

        //std::cout << clk.getElapsedTime().asMilliseconds() << std::endl;

        // testing terminator movement
        terminator.moveLeft();
        window.draw(terminator);

        // Update the window
        window.display();
    }
}