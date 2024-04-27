#include "game.h"

Game::Game() {
    m_game_texture.loadFromFile("resources/back2.jpg");
    m_game_sprite.setTexture(m_game_texture);
}

void Game::setState(GameState state) {
    m_game_state = state;
}

GameState Game::getState() const {
    return m_game_state;
}

void Game::Start(sf::RenderWindow& window) {

    sf::Music music;
    music.openFromFile("resources/back1.mp3");
    music.play();

    sf::Clock clock;
    sf::Time dt;
    sf::Event event;
    Ball ball(1280 / 2, 10.0);
    Paddle paddle(1280 / 2, 705);

    while (window.isOpen() && m_game_state == GameState::ON) {
        dt = clock.restart();

        if (ball.getPosition().intersects(paddle.getPosition()) && (ball.getPosition().top + ball.getPosition().width > paddle.getPosition().top)) {
            ball.hitBall();
        }

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
            m_game_state = GameState::MENU;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            paddle.moveLeft();
        }
        else {
            paddle.stopLeft();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            paddle.moveRight();
        }
        else {
            paddle.stopRight();
        }

        if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > 1280) {
            ball.bounceSides();
        }

        if (ball.getPosition().top < 0) {
            ball.bounceTop();
        }

        if (ball.getPosition().top + ball.getPosition().height > 720) {
            m_game_state = GameState::LOSE;
        }

        window.clear();
        ball.update(dt);
        paddle.update(dt);

        window.draw(m_game_sprite);
        window.draw(ball.getShape());
        window.draw(paddle.getShape());
        window.display();
    }
}