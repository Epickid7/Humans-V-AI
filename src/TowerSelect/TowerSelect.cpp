#include "TowerSelect.h"

void TowerSelect::displayTowerList(sf::RenderWindow& window)
{
    const sf::Font font = Utilities::getAttributedFont(FontStyle::SemiBoldItalic, "SF-Pro");
    int x = 20;
    int k = 18;

    sf::Text text1(font, "Bank (1)", 30);
    sf::Text text2(font, "Barricade (2)", 30);
    sf::Text text3(font, "Landmine (3)", 30);
    sf::Text text4(font, "Mortar (4)", 30);
    sf::Text text5(font, "People (5)", 30);
    sf::Text text6(font, "Rifleman (6)", 30);
    sf::Text text7(font, "Stickman (7)", 30);
    sf::Text text8(font, "Tank (8)", 30);
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
       /* towerToPlace = new Barricade(0, 0);*/
        std::cout << "Pressing Key 2" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) { //Landmine
        this->curTower = 3;
        /*towerToPlace = new Bank(0, 0);*/
        std::cout << "Pressing Key 3" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4)) { //Mortar
        this->curTower = 4;
        /*towerToPlace = new Bank(0, 0);*/
        std::cout << "Pressing Key 4" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5)) { //People
        this->curTower = 5;
        //this->towerToPlace = new People(0, 0);
        std::cout << "Pressing Key 5" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num6)) { //Rifleman
        this->curTower = 6;
       /* towerToPlace = new Bank(0, 0);*/
        std::cout << "Pressing Key 6" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num7)) { //Stickman
        this->curTower = 7;
       /* towerToPlace = new Bank(0, 0);*/
        std::cout << "Pressing Key 7" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num8)) { //Tank
        this->curTower = 8;
       /* towerToPlace = new Bank(0, 0);*/
        std::cout << "Pressing Key 8" << std::endl;
    }
}

bool TowerSelect::checkForTowerPlace(GridTile** gameBoard[ROW][COLUMN], sf::Vector2f& mouse, std::vector<sf::Sprite>& towerVector)
{
    return false;
}

int TowerSelect::getCurTower(void)
{
    return this->curTower;
}
