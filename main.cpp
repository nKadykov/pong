#include <iostream>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"

int main()
{   
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Pong");
    window.setFramerateLimit(60);
    sf::Clock clock;
    sf::Time dt;
    sf::Event event;
    Ball myball(1280, 2.0);
    Paddle myPaddle(1280 / 2, 715);

    while (window.isOpen()) {
        dt = clock.restart();

        if (myball.getPosition().intersects(myPaddle.getPosition())) {
            myball.hitBall();
        }

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            myPaddle.moveLeft();
        }
        else {
            myPaddle.stopLeft();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            myPaddle.moveRight();
        }
        else {
            myPaddle.stopRight();
        }

        if (myball.getPosition().left < 0 || myball.getPosition().left + myball.getPosition().width > 1280) {
            myball.bounceSides();
        }

        if (myball.getPosition().top < 0) {
            myball.bounceTop();
        }

        if (myball.getPosition().top + myball.getPosition().height > 720) {
            myball.missBottom();
        }

        window.clear();
        myball.update(dt);
        myPaddle.update(dt);

        window.draw(myball.getShape());
        window.draw(myPaddle.getShape());
        window.display();
    }
}