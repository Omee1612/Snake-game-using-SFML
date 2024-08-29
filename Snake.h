//
// Created by Omee on 8/30/2024.
//

#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>

class Snake {
private:
    sf::VideoMode vMode;
    std::shared_ptr<sf::RenderWindow> window;
    std::vector<sf::CircleShape> snake;
    sf::Event event;
    sf::CircleShape snakeBod;
    sf::RectangleShape food;
public:
    Snake();
    virtual ~Snake ()=default;
    void initWindow();
    void initFood();
    void update();
    void render();
    bool windowStat();
    void pollEvents();
};


#endif //SNAKEGAME_SNAKE_H
