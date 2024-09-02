#include "Snake.h"

void Snake::initWindow() {
    vMode.height = 1080;
    vMode.width = 1920;
    window = std::make_shared<sf::RenderWindow>(vMode, "Snake", sf::Style::Titlebar);
    window->setFramerateLimit(10);  // Reduce frame rate for better control
}

void Snake::updateMovement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !moveLeft) {
        moveRight = true; moveLeft = false; moveUp = false; moveDown = false;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !moveDown) {
        moveRight = false; moveLeft = false; moveUp = true; moveDown = false;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !moveRight) {
        moveRight = false; moveLeft = true; moveUp = false; moveDown = false;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !moveUp) {
        moveRight = false; moveLeft = false; moveUp = false; moveDown = true;
    }
}

void Snake::initSnake() {
    snake.clear();
    sf::CircleShape segment(10);
    segment.setFillColor(sf::Color(160, 24, 240));
    for (int i = 0; i < 3; ++i) {  // Start with fewer segments
        segment.setPosition(960 - i * 20, 540); // Initial spacing
        snake.push_back(segment);
    }
    Lost = false;
    direction = sf::Vector2f(20.f, 0.f);  // Initial direction
}

void Snake::createFood() {
    apple = std::make_shared<sf::Sprite>();
    if (!texture.loadFromFile("apple.png")) {
        std::cerr << "Error loading texture";
        return;
    }
    apple->setTexture(texture);
    apple->setScale(0.15, 0.15);
    apple->setPosition(rand() % (window->getSize().x - 30), rand() % (window->getSize().y - 30)); // Ensure apple is within window
}

void Snake::feedLogic() {
    if (snake.front().getGlobalBounds().intersects(apple->getGlobalBounds())) {
        createFood();
        sf::CircleShape newSegment(10);
        newSegment.setFillColor(sf::Color(160, 24, 240));
        newSegment.setPosition(snake.back().getPosition()); // Place at the last segment's position
        snake.push_back(newSegment);
    }
}

void Snake::moveSnake() {
    if (Lost) return;

    // Move the body segments
    sf::Vector2f newHeadPos = snake.front().getPosition();
    if (moveRight) direction = sf::Vector2f(20.f, 0.f);
    if (moveLeft) direction = sf::Vector2f(-20.f, 0.f);
    if (moveUp) direction = sf::Vector2f(0.f, -20.f);
    if (moveDown) direction = sf::Vector2f(0.f, 20.f);

    // Move the head
    newHeadPos += direction;
    snake.push_front(snake.front());
    snake.front().setPosition(newHeadPos);

    // Remove the tail segment if not eating
    if (snake.size() > 3) {
        snake.pop_back();
    }
}

void Snake::checkCollision() {
    // Check collision with the window boundaries
    const sf::Vector2f& headPos = snake.front().getPosition();
    if (headPos.x >= window->getSize().x || headPos.y >= window->getSize().y ||
        headPos.x < 0 || headPos.y < 0) {
        Lost = true;
        return;
    }

    // Check collision with itself
    for (size_t i = 1; i < snake.size(); ++i) {
        if (snake.front().getGlobalBounds().intersects(snake[i].getGlobalBounds())) {
            Lost = true;
            return;
        }
    }
}

void Snake::renderSnake() {
    for (const auto& segment : snake) {
        window->draw(segment);
    }
}

void Snake::render() {
    window->clear();
    if (Lost) {
        sf::Text text;
        text.setFont(font3);
        text.setString("You lose!");
        text.setCharacterSize(40);
        text.setFillColor(sf::Color::Green);
        window->draw(text);
    }
    window->draw(*apple);
    renderSnake();
    window->display();
}

void Snake::update() {
    pollEvents();
    updateMovement();
    moveSnake();
    checkCollision();
    feedLogic();
}

void Snake::pollEvents() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
            window->close();
        }
    }
}

void Snake::compileText() {
    if (!font1.loadFromFile("bigspace.ttf")) {
        std::cerr << "Error loading font1";
        return;
    }
    if (!font2.loadFromFile("evilem.ttf")) {
        std::cerr << "Error loading font2";
        return;
    }
    if (!font3.loadFromFile("superpix.ttf")) {
        std::cerr << "Error loading font3";
        return;
    }
}

bool Snake::windowStat() {
    return window->isOpen();
}

Snake::Snake() {
    initWindow();
    initSnake();
    createFood();
    compileText();
}