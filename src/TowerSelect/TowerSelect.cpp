#include "TowerSelect.h"

void TowerSelect::displayTowerList(sf::RenderWindow& window)
{
    const sf::Font font = Utilities::getAttributedFont(FontStyle::SemiBoldItalic, "SF-Pro");


    sf::Text text1(font, "Bank (1)", 30);
    sf::Text text2(font, "Barricade (2)", 30);
    sf::Text text3(font, "Landmine (3)", 30);
    sf::Text text4(font, "Mortar (4)", 30);
    sf::Text text5(font, "People (5)", 30);
    sf::Text text6(font, "Rifleman (6)", 30);
    sf::Text text7(font, "Stickman (7)", 30);
    sf::Text text8(font, "Tank (8)", 30);
    text1.setPosition(sf::Vector2f(0, 40));
    text2.setPosition(sf::Vector2f(0, 40));
    text3.setPosition(sf::Vector2f(0, 40));
    text4.setPosition(sf::Vector2f(0, 40));
    text5.setPosition(sf::Vector2f(0, 40));
    text6.setPosition(sf::Vector2f(0, 40));
    text7.setPosition(sf::Vector2f(0, 40));
    text8.setPosition(sf::Vector2f(0, 40));
    
    window.draw(text1);
    window.draw(text2);
    window.draw(text3);
    window.draw(text4);
    window.draw(text5);
    window.draw(text6);
    window.draw(text7);
    window.draw(text8);
}
