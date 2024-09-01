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

void Snake::feedLogic() {
    if (snake[0].getGlobalBounds().intersects(food->getGlobalBounds()))
    {
        food = std::make_shared<sf::RectangleShape>();
        food->setFillColor(sf::Color::Cyan);
        food->setSize(sf::Vector2f(100.f, 100.f));
        food->setScale(0.25, 0.25);
        food->setPosition(rand() % 1910, rand() % 1060);
        addSegment();
        addSegment();
        addSegment();
        addSegment();
        addSegment();
        addSegment();
        addSegment();
    }
}

void Snake::addSegment() {
    sf::CircleShape segment(30);
    segment.setFillColor(sf::Color(160, 24, 240));
    segment.setPosition(960 - i * 60, 540); // Initial positioning
    snake.push_back(segment);
    i++;
}

void Snake::loseLogic() {
    if (snake[0].getPosition().x >= window->getSize().x || snake[0].getPosition().y >= window->getSize().y ||
        snake[0].getPosition().x < 0 || snake[0].getPosition().y < 0) {
        if (!Lost) clock.restart();
        Lost = true;
        if (clock.getElapsedTime().asSeconds() > 4)
            window->close();
    }
}

void Snake::initSnake() {
    for (i = 0; i < 30; i++) {
        sf::CircleShape segment(30);
        segment.setFillColor(sf::Color(160, 24, 240));
        segment.setPosition(960 - i * 60, 540); // Initial positioning
        snake.push_back(segment);
    }
    Lost = false;
    std::cout << "Initialized " << snake.size() << " snake segments.\n"; // Debugging
}

void Snake::renderSnake() {
    for (auto &s: snake) {
        window->draw(s);
    }
}

void Snake::moveSnakeVec() {
    if (!Lost) {
        for (int i = snake.size() - 1; i > 0; i--) {
            snake[i].setPosition(snake[i - 1].getPosition());
        }
        sf::Vector2f headPos = snake[0].getPosition();
        if (moveRight) {
            headPos.x += 5.f;
        } else if (moveLeft) {
            headPos.x -= 5.f;
        } else if (moveUp) {
            headPos.y -= 5.f;
        } else if (moveDown) {
            headPos.y += 5.f;
        }
        snake[0].setPosition(headPos);
    }
}

Snake::Snake() {
    initBool();
    initWindow();
    initFood();
    initSnake();
    compileText();
}

void Snake::initFood() {
    food = std::make_shared<sf::RectangleShape>();
    food->setFillColor(sf::Color::Cyan);
    food->setSize(sf::Vector2f(100.f, 100.f));
    food->setScale(0.25, 0.25);
    food->setPosition(rand() % 1920, rand() % 1080);
}

void Snake::update() {
    pollEvents();
    updateMovement();
    moveSnakeVec();
    feedLogic();
    loseLogic();
}

void Snake::pollEvents() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) window->close();
        if (event.key.code == (sf::Keyboard::Escape)) window->close();
    }
}

void Snake::compileText() {
    if(!font1.loadFromFile("bigspace.ttf"))
    {
        std::cerr << "Error loading font1";
        return;
    }
    if(!font2.loadFromFile("evilem.ttf"))
    {
        std::cerr << "Error loading font3";
        return;
    }
    if(!font3.loadFromFile("superpix.ttf"))
    {
        std::cerr << "Error loading font2";
        return;
    }
}

bool Snake::windowStat() {
    return window->isOpen();
}

void Snake::render() {
    sf::Text text;
    text.setFont(font3);
    text.setString("You lose!");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Green);
    window->clear();
    if(Lost) window->draw(text);
    window->draw(*food);
    renderSnake();
    window->display();
}
