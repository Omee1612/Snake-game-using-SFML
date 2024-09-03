//
// Created by Omee on 9/3/2024.
//

#ifndef SNAKEGAME_MAINMENU_H
#define SNAKEGAME_MAINMENU_H
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

class MainMenu {
private:
    sf::Text text;
    sf::Text playText;
    sf::Text exitText;
    sf::Font font;
    sf::Font font2;
    sf::Event event;
    std::shared_ptr<sf::RenderWindow> window;
    bool menuActive = true;
    int choice=1;
    sf::RectangleShape mark;
    void choiceOptions();
public:
    void pollEvents();
    MainMenu(std::shared_ptr<sf::RenderWindow> win);
    void render();
    void update();
    bool isActive();
};


#endif //SNAKEGAME_MAINMENU_H
