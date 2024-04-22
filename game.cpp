#include "game.h"

Game::Game() {
    game_texture.loadFromFile("resources/back2.jpg");
    game_sprite.setTexture(game_texture);
}

void Game::setState(GameState state) {
    game_state = state;
}

GameState Game::getState() const {
    return game_state;
}

void Game::Start(sf::RenderWindow& window) {
    sf::Clock clock;
    sf::Time dt;
    sf::Event event;
    Ball my_ball(1280 / 2, 2.0);
    Paddle my_paddle(1280 / 2, 705);

    while (window.isOpen() && game_state == GameState::ON) {
        dt = clock.restart();

        if (my_ball.getPosition().intersects(my_paddle.getPosition())) {
            my_ball.hitBall();
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
            game_state = GameState::MENU;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            my_paddle.moveLeft();
        }
        else {
            my_paddle.stopLeft();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            my_paddle.moveRight();
        }
        else {
            my_paddle.stopRight();
        }

        if (my_ball.getPosition().left < 0 || my_ball.getPosition().left + my_ball.getPosition().width > 1280) {
            my_ball.bounceSides();
        }

        if (my_ball.getPosition().top < 0) {
            my_ball.bounceTop();
        }

        if (my_ball.getPosition().top + my_ball.getPosition().height > 720) {
            game_state = GameState::LOSE;
        }

        window.clear();
        my_ball.update(dt);
        my_paddle.update(dt);

        window.draw(game_sprite);
        window.draw(my_ball.getShape());
        window.draw(my_paddle.getShape());
        window.display();
    }
}