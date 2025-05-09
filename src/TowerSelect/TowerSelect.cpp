#include "TowerSelect.h"

void TowerSelect::displayTowerList(sf::RenderWindow& window)
{
    const sf::Font font = Utilities::getAttributedFont(FontStyle::SemiBoldItalic, "SF-Pro");
    int x = 20;
    int k = 18;

    sf::Text text1(font, "(1) Bank", 30);
    sf::Text text2(font, "(2) Barricade", 30);
    sf::Text text3(font, "(3) Landmine~", 30);
    sf::Text text4(font, "(4) Mortar~", 30);
    sf::Text text5(font, "(5) People", 30);
    sf::Text text6(font, "(6) Rifleman~", 30);
    sf::Text text7(font, "(7) Stickman~", 30);
    sf::Text text8(font, "(8) Tank~", 30);
    text1.setPosition(sf::Vector2f(0, 0*window.getSize().y/x +window.getSize().y/k));
    text2.setPosition(sf::Vector2f(0, 1*window.getSize().y / x + window.getSize().y / k));
    text3.setPosition(sf::Vector2f(0, 2*window.getSize().y / x + window.getSize().y / k));
    text4.setPosition(sf::Vector2f(0, 3*window.getSize().y / x + window.getSize().y / k));
    text5.setPosition(sf::Vector2f(0, 4*window.getSize().y / x + window.getSize().y / k));
    text6.setPosition(sf::Vector2f(0, 5*window.getSize().y / x + window.getSize().y / k));
    text7.setPosition(sf::Vector2f(0, 6*window.getSize().y / x + window.getSize().y / k));
    text8.setPosition(sf::Vector2f(0, 7*window.getSize().y / x + window.getSize().y / k));
    
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);
    window.draw(text4);
    window.draw(text5);
    window.draw(text6);
    window.draw(text7);
    window.draw(text8);
}

void TowerSelect::setCurTower(int newCurTower)
{
    this->curTower = newCurTower;
}

//This function should be called to check keyboard input events and update private member 
// as to which tower is selected
void TowerSelect::checkForTowerSelect()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) { //Bank
        this->curTower = 1;
       /* towerToPlace = new Bank();*/
        std::cout << "Pressing Key 1" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) { //Barricade
        this->curTower = 2;
      
        std::cout << "Pressing Key 2" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) { //Landmine
        this->curTower = 3;
   
        std::cout << "Pressing Key 3" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4)) { //Mortar
        this->curTower = 4;
     
        std::cout << "Pressing Key 4" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5)) { //People
        this->curTower = 5;
        //this->towerToPlace = new People(0, 0);
        std::cout << "Pressing Key 5" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num6)) { //Rifleman
        this->curTower = 6;
       
        std::cout << "Pressing Key 6" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num7)) { //Stickman
        this->curTower = 7;
     
        std::cout << "Pressing Key 7" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num8)) { //Tank
        this->curTower = 8;
    
        std::cout << "Pressing Key 8" << std::endl;
    }
}

bool TowerSelect::checkForTowerPlace(sf::RenderWindow& window, GridTile* gameBoard[ROW][COLUMN], sf::Vector2f& mouse, std::vector<Tower>& towerVector)
{
    Bank* newBank = nullptr;
    People* newPeople = nullptr;
    //Bank b(0,0);
    Barricade* newBarricade = nullptr;

    //NEED TO CHECK IF THERE IS ALREADY A TOWER PLACED IN A SQUARE SOMEWHERE (TODO)

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COLUMN; j++) {
                // we need overloaded assignment operator
                //declare with texture?

                if ((*gameBoard[i][j]).getGlobalBounds().contains(sf::Vector2f(mouse.x,
                    mouse.y))) {

                    //switch statement for which type of tower
                    switch (this->curTower) {
                    case 1:
                        //b.setPosition({ (*gameBoard[i][j]).getPosition().x, (*gameBoard[i][j]).getPosition().y });
                        newBank = new Bank((*gameBoard[i][j]).getPosition().x, (*gameBoard[i][j]).getPosition().y);
                        towerVector.push_back(*newBank);
                        break;
                    case 2:
                        //newBarricade = new Barricade((*gameBoard[i][j]).getPosition().x, (*gameBoard[i][j]).getPosition().y);
                        towerVector.push_back(*newBarricade);
                        break;
                    case 3:
                        //newBank = new Bank;
                        break;
                    case 4:
                        //newBank = new Bank;
                        break;
                    case 5:
                        newPeople = new People();
                        //newPeople = new People((int)(*gameBoard[i][j]).getPosition().x, (int)(*gameBoard[i][j]).getPosition().y);
                        newPeople->setPosition(sf::Vector2f( (*gameBoard[i][j]).getPosition().x, (*gameBoard[i][j]).getPosition().y ));
                        if (newPeople) {
                            towerVector.push_back(*newPeople);
                        }
                        std::cout << "spawning People" << std::endl;
                        break;
                    case 6:
                        
                       
                        break;
                    case 7:
                        //newBank = new Bank;
                        break;
                    case 8:
                        //newBank = new Bank;
                        break;
                    }


                    /*sprite = new sf::Sprite(s);
                    (*sprite).setPosition({ (*gameBoard[i][j]).getPosition().x, (*gameBoard[i][j]).getPosition().y });
                    (*sprite).setColor(sf::Color::White);
                    towerVector.push_back(*sprite);*/



                }
            }
        }
    }
    std::cout << "end of Towerselect" << std::endl;
    return false;
   
}

int TowerSelect::getCurTower(void)
{
    return this->curTower;
}
