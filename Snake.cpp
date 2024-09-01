#include "Snake.h"

void Snake::initWindow() {
    vMode.height = 1080;
    vMode.width = 1920;
    window = std::make_shared<sf::RenderWindow>(vMode, "Snake",
                                                sf::Style::Titlebar);
    window->setFramerateLimit(75);
}

void Snake::updateMovement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !moveLeft) {
        moveRight = true;
        moveLeft = false;
        moveUp = false;
        moveDown = false;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !moveDown) {
        moveRight = false;
        moveLeft = false;
        moveUp = true;
        moveDown = false;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !moveRight) {
        moveRight = false;
        moveLeft = true;
        moveUp = false;
        moveDown = false;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !moveUp) {
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
    for( int i = snake.size() - 1; i >0; i--) {
        snake[i].setPosition(snake[i-1].getPosition());
    }
    sf::Vector2f headPos = snake[0].getPosition();
    if(moveRight)
    {
        headPos.x += 5.f;
    }
    else if (moveLeft)
    {
        headPos.x -= 5.f;
    }
    else if (moveUp)
    {
        headPos.y -= 5.f;
    }
    else if (moveDown)
    {
        headPos.y += 5.f;
    }
    snake[0].setPosition(headPos);
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
    updateMovement();
    moveSnakeVec();
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
