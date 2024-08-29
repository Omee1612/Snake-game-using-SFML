//
// Created by Omee on 8/30/2024.
//

#include "Snake.h"

void Snake::initWindow() {
    vMode.height = 1080;
    vMode.width = 1920;
    window = std::make_shared<sf::RenderWindow>(vMode, "Snake",
                                          sf::Style::Titlebar);
}
Snake::Snake() {
    initWindow();
    initFood();
}
void Snake::initFood() {
    food.setFillColor(sf::Color::Cyan);
    food.setSize(sf::Vector2f(100.f,100.f));
    food.setScale(0.25,0.25);
    food.setPosition(rand() % 1920 + 1, rand() % + 1080+1);
}

void Snake::update() {
pollEvents();
}
void Snake::pollEvents() {
    while (window->pollEvent(event)) {
        if(event.type == sf::Event::Closed) window->close();
        if(event.key.code == (sf::Keyboard::Escape)) window->close();
    }
}
bool Snake::windowStat() {
    return window->isOpen();
}
void Snake::render() {
    window->clear();
    window->draw(food);
    window->display();
}
