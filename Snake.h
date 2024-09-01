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
    bool moveRight;
    bool moveLeft;
    bool moveUp;
    bool moveDown;
    std::shared_ptr<sf::RenderWindow> window;
    std::vector<sf::CircleShape> snake;
    sf::Event event;
    sf::Vector2f direction{0.04f,0.f};
    sf::RectangleShape food;
public:
    Snake();

    virtual ~Snake() = default;

    void initWindow();

    void initFood();

    void update();

    void renderSnake();

    void render();

    bool windowStat();

    void pollEvents();


    void initSnake();

    void moveSnakeVec();

    void initBool();

    void updateMovement();

    void feedLogic();
};


#endif //SNAKEGAME_SNAKE_H
