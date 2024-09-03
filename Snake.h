#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cstdlib>
#include <deque>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
class MainMenu;
class Snake {
private:
    sf::VideoMode vMode;
    bool moveRight;
    bool moveLeft;
    bool moveUp;
    bool moveDown;
    sf::Texture texture;
    std::shared_ptr<sf::Sprite> apple;
    std::shared_ptr<sf::RenderWindow> window;
    sf::Clock clock;
    sf::Vector2f direction;
    std::deque<sf::CircleShape> snake;
    bool Lost;
    sf::Font font1;
    sf::Font font2;
    sf::Font font3;
    sf::Event event;
    MainMenu *menu;
public:
    Snake();
    virtual ~Snake();

    void initWindow();
    void initSnake();
    void compileText();

    void update();
    void render();

    bool windowStat();

private:
    void createFood();
    void updateMovement();
    void moveSnake();
    void checkCollision();
    void feedLogic();
    void pollEvents();
    void renderSnake();
};

#endif //SNAKEGAME_SNAKE_H