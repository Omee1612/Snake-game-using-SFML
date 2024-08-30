#include "Snake.h"

void Snake::initWindow() {
    vMode.height = 1080;
    vMode.width = 1920;
    window = std::make_shared<sf::RenderWindow>(vMode, "Snake",
                                                sf::Style::Titlebar);
}

void Snake::updateMovement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        moveRight = true;
        moveLeft = false;
        moveUp = false;
        moveDown = false;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        moveRight = false;
        moveLeft = false;
        moveUp = true;
        moveDown = false;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        moveRight = false;
        moveLeft = true;
        moveUp = false;
        moveDown = false;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        moveRight = false;
        moveLeft = false;
        moveUp = false;
        moveDown = true;
    }
}

void Snake::initBool() {
    moveRight = true;
    moveLeft = false;
    moveUp = false;
    moveDown = false;
}

void Snake::initSnake() {
    for (int i = 0; i < 5; i++) {
        sf::CircleShape segment(30);
        segment.setFillColor(sf::Color(160, 24, 240));
        segment.setPosition(960 - i * 60, 540); // Initial positioning
        snake.push_back(segment);
    }
    std::cout << "Initialized " << snake.size() << " snake segments.\n"; // Debugging
}

void Snake::renderSnake() {
    for (auto &s: snake) {
        window->draw(s);
    }
}

void Snake::moveSnakeVec() {
    for (auto &s: snake) {
        if (moveRight) {
            s.move(0.04, 0.f);
        }
        else if (moveLeft) {
            s.move(-0.04, 0.f);
        }
        else if (moveUp) {
            s.move(0.f, -0.04);
        }
        else if (moveDown) {
            s.move(0.f, 0.04);
        }
    }
}

Snake::Snake() {
    initBool();
    initWindow();
    initFood();
    initSnake();
}


void Snake::initFood() {
    food.setFillColor(sf::Color::Cyan);
    food.setSize(sf::Vector2f(100.f, 100.f));
    food.setScale(0.25, 0.25);
    food.setPosition(rand() % 1920, rand() % 1080);
}

void Snake::update() {
    pollEvents();
    moveSnakeVec();
    updateMovement();
}

void Snake::pollEvents() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) window->close();
        if (event.key.code == (sf::Keyboard::Escape)) window->close();
    }
}

bool Snake::windowStat() {
    return window->isOpen();
}

void Snake::render() {
    window->clear();
    window->draw(food);
    renderSnake();
    window->display();
}
