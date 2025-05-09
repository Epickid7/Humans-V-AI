/*
Authors: Ian Van De Bogert, Jacob Parnell, Jayren Calub, Parker Mulroy
Data: 4/23/25
Project: PA9 group graphical project

Description: The program uses the SFML 3.0 library to create a tower defense game with graphics. The theme of this game is "Humans vs AI", and currently has three placeable
sprites of towers. They do not work as intended, but they can be placed on the game board. 
*/



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
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Humans v AI");
    window.setVerticalSyncEnabled(true);
    //set mouse to window position
    sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    
    sf::Clock clk;

    //People p(0,0);

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


    sf::Texture bankText(ASSETS_PATH "/images/bank.png");

    sf::Texture barricadeText(ASSETS_PATH "/images/barricade.png");

    //sf::Texture bankTest(ASSETS_PATH "/images/bank.png");

    //sf::Texture bankTest(ASSETS_PATH "/images/bank.png");

    sf::Texture peopleText(ASSETS_PATH "/images/people.png");

    //sf::Texture bankTest(ASSETS_PATH "/images/bank.png");

    //sf::Texture bankTest(ASSETS_PATH "/images/bank.png");

    //sf::Texture bankTest(ASSETS_PATH "/images/bank.png");

    sf::Sprite bank(bankText);

    sf::Sprite barricade(barricadeText);

   //sf::Sprite s(bankTest);

    //sf::Sprite s(bankTest);

    sf::Sprite people(peopleText);

    //sf::Sprite s(bankTest);

    //sf::Sprite s(bankTest);

    //sf::Sprite s(bankTest);
   

    //test texture
    sf::Texture t(ASSETS_PATH "/images/grassTile.png",false, sf::IntRect({ 0,0 },
        { 67,120 }));
    sf::Texture toasterTexutre(ASSETS_PATH "/images/toaster.png");
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

    int lastKeyPressed = 0;

    //vector of sprites
    //will change to tower type
    vector<sf::Sprite> towerVector;
    vector<sf::Sprite> machineVector;
    //vector<Tower> towerVector;

    // spawn toasters
    sf::Sprite* machine1 = new sf::Sprite(toasterTexutre);
    sf::Sprite* machine2 = new sf::Sprite(toasterTexutre);
    sf::Sprite* machine3 = new sf::Sprite(toasterTexutre);
    sf::Sprite* machine4 = new sf::Sprite(toasterTexutre);
    sf::Sprite* machine5 = new sf::Sprite(toasterTexutre);

    machine1->setPosition({ 700, 0 });
    machine2->setPosition({ 700, 115 });
    machine3->setPosition({ 700, 230 });
    machine4->setPosition({ 700, 345 });
    machine5->setPosition({ 700, 460 });

    machineVector.push_back(*machine1);
    machineVector.push_back(*machine2);
    machineVector.push_back(*machine3);
    machineVector.push_back(*machine4);
    machineVector.push_back(*machine5);

    std::vector<Projectile> projectiles;

   
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

    // Start the game loop

    //clk.start();

       // Main Menu loop
    // Process events
    while (const std::optional event = window.pollEvent())
    {
        // Close window: exit
        if (event->is<sf::Event::Closed>())
            window.close();
    }
    // Clear screen
    window.clear();
    sf::Vector2u windowSize = window.getSize();

    sf::Text title(font, "HUMANS VS. AI", 30U);
    title.setPosition(sf::Vector2f());
    sf::Text instruct(font, "This is a TOWER DEFENSE game. Earn money by placing banks,\n then use that money to buy other towers to defend your base\n from the evil AI-controlled robots. Fight for your survival...\n ONLY HIT ENTER OR THIS PROGRAM WILL CRASH. DO NOT CLICK THE SCREEN!!!", 15U);
    instruct.setPosition(sf::Vector2f(100, 200));
    sf::Text game(font, "PRESS ENTER TO CONTINUE", 30U);
    game.setPosition(sf::Vector2f(300, 350));
    bool menu = true;

    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && window.isOpen())
    {
        // Update window size after maximizing
        window.clear(sf::Color::Black); // set background to balck
        window.draw(title); // draws the title
        window.draw(instruct); // draws the instructions
        window.draw(game); // draws the continuation instructions
        window.display();
    }

    // GAMEPLAY LOOP BEGINS HERE
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
        

        //will spawn every five seconds

        
        if (clk.getElapsedTime().asMilliseconds() % 5000 == 0) {
            
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
                        switch (lastKeyPressed) {
                        case 1:
                            sprite = new sf::Sprite(bank);
                            (*sprite).setPosition({ (*gameBoard[i][j]).getPosition().x, (*gameBoard[i][j]).getPosition().y });
                            //(*sprite).setColor(sf::Color::White);
                            towerVector.push_back(*sprite);
                            break;
                        case 2:
                            sprite = new sf::Sprite(barricade);
                            (*sprite).setPosition({ (*gameBoard[i][j]).getPosition().x, (*gameBoard[i][j]).getPosition().y });
                            //(*sprite).setColor(sf::Color::White);
                            towerVector.push_back(*sprite);
                            break;
                        case 3:
                            //sprite = new sf::Sprite(bank);
                            //(*sprite).setPosition({ (*gameBoard[i][j]).getPosition().x, (*gameBoard[i][j]).getPosition().y });
                            ////(*sprite).setColor(sf::Color::White);
                            //towerVector.push_back(*sprite);
                            break;
                        case 4:
                            //sprite = new sf::Sprite(bank);
                            //(*sprite).setPosition({ (*gameBoard[i][j]).getPosition().x, (*gameBoard[i][j]).getPosition().y });
                            ////(*sprite).setColor(sf::Color::White);
                            //towerVector.push_back(*sprite);
                            break;
                        case 5:
                            sprite = new sf::Sprite(peopleText);
                            (*sprite).setPosition({ (*gameBoard[i][j]).getPosition().x, (*gameBoard[i][j]).getPosition().y });
                            //(*sprite).setColor(sf::Color::White);
                            towerVector.push_back(*sprite);
                            break;
                        case 6:
                            //sprite = new sf::Sprite(bank);
                            //(*sprite).setPosition({ (*gameBoard[i][j]).getPosition().x, (*gameBoard[i][j]).getPosition().y });
                            ////(*sprite).setColor(sf::Color::White);
                            //towerVector.push_back(*sprite);

                            break;
                        case 7:
                            //sprite = new sf::Sprite(bank);
                            //(*sprite).setPosition({ (*gameBoard[i][j]).getPosition().x, (*gameBoard[i][j]).getPosition().y });
                            ////(*sprite).setColor(sf::Color::White);
                            //towerVector.push_back(*sprite);
                            break;
                        case 8:
                            //sprite = new sf::Sprite(bank);
                            //(*sprite).setPosition({ (*gameBoard[i][j]).getPosition().x, (*gameBoard[i][j]).getPosition().y });
                            ////(*sprite).setColor(sf::Color::White);
                            //towerVector.push_back(*sprite);
                            break;
                        }
                        
                       
                        
                       
                    }
                }
            }
        }

        //Draw money
        sf::Text money(font, sf::String( std::to_string(player.getMoney())), 35);
        money.setPosition(sf::Vector2f(0, 0));
        window.draw(money);

        //draw menu for choosing tower
        selectMenu.displayTowerList(window);
        selectMenu.checkForTowerSelect();
        lastKeyPressed = selectMenu.getCurTower();
        //check if user is clicking a tile
        //selectMenu.checkForTowerPlace(window, gameBoard, mouse, towerVector);
       
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
        for (int i = 0; i < machineVector.size(); i++) {
            machineVector.at(i).move({ -0.5, 0 });
            window.draw(machineVector.at(i));
        }

        //// testing terminator movement
        //terminator.moveLeft();
        //window.draw(terminator);

        // Update the window
        window.display();
    }
}