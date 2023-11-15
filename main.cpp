#include <SFML/Graphics.hpp>
#include "Ball.h"

int main()
{
    sf::VideoMode VM(1280, 720);
    sf::RenderWindow window(VM, "Pong");
    sf::Clock clock;
    sf::Time dt;
    Ball myball(1280, 2.0);

    while (window.isOpen()) {
        dt = clock.restart();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
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
        window.draw(myball.getShape());
        window.display();
    }
}