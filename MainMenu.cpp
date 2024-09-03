//
// Created by Omee on 9/3/2024.
//

#include "MainMenu.h"

MainMenu::MainMenu(std::shared_ptr<sf::RenderWindow> win) : window(win), menuActive(true) {
    if (!font.loadFromFile("evilem.ttf")) {
        std::cerr << "Error loading font evilem";
        return;
    }
    if (!font2.loadFromFile("superpix.ttf")) {
        std::cerr << "Error loading font superpx";
        return;
    }
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(60);
    text.setPosition(1760 / 2.f - text.getGlobalBounds().width / 2.f,
                     700 / 2.f - text.getGlobalBounds().height / 2.f);
    text.setString("Omee's\nSnake\nGame");
    playText.setFont(font2);
    playText.setFillColor(sf::Color::White);
    playText.setCharacterSize(40);
    playText.setString("PLAY");
    playText.setPosition(1800 / 2.f - playText.getGlobalBounds().width / 2.f,
                         1400 / 2.f - playText.getGlobalBounds().height / 2.f);
    exitText.setFont(font2);
    exitText.setFillColor(sf::Color::White);
    exitText.setCharacterSize(40);
    exitText.setString("QUIT");
    exitText.setPosition(1800 / 2.f - playText.getGlobalBounds().width / 2.f,
                         1500 / 2.f - playText.getGlobalBounds().height / 2.f);
    mark.setSize(sf::Vector2f(10, 10));
    mark.setFillColor(sf::Color::Green);
    mark.setPosition(playText.getPosition().x - 30, playText.getPosition().y + 20);
}

bool MainMenu::isActive() {
    return menuActive;
}


void MainMenu::update() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            window->close();
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up && choice == 2) {
            choice = 1;
            mark.setPosition(playText.getPosition().x - 30, playText.getPosition().y + 20);
        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up && choice == 1){
            choice = 2;
            mark.setPosition(exitText.getPosition().x - 30, exitText.getPosition().y + 20);
        }
       else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down && choice == 1) {
            choice = 2;
            mark.setPosition(exitText.getPosition().x - 30, exitText.getPosition().y + 20);
        }
        else if ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down && choice == 2){
            choice = 1;
            mark.setPosition(playText.getPosition().x - 30, playText.getPosition().y + 20);
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && choice == 1)
            menuActive = false;
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && choice == 2)
            window->close();
    }
}

void MainMenu::render() {
    window->clear();
    window->draw(text);
    window->draw(playText);
    window->draw(exitText);
    window->draw(mark);
    window->display();
}