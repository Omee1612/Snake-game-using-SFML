#include "Snake.h"

void Snake::initWindow() {
    vMode.height = 1080;
    vMode.width = 1920;
    window = std::make_shared<sf::RenderWindow>(vMode, "Snake",
                                                sf::Style::Titlebar);
}

void Snake::initSnake() {
    for (int i = 0; i < 5; i++) {
        sf::CircleShape segment(30);
        segment.setFillColor(sf::Color(160, 24, 240));
        segment.setPosition(960 - i * 30, 540); // Initial positioning
        snake.push_back(segment);
    }
    std::cout << "Initialized " << snake.size() << " snake segments.\n"; // Debugging
}

void Snake::renderSnake() {
    for (const auto &s : snake) {
        window->draw(s);
    }
}

Snake::Snake() {
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
