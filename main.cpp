#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.h"
#include "gameoverwindow.h"
#include "menu.h"

enum class State { GAME, GAMEOVER, MENU };

int main()
{   
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Pong");
    window.setFramerateLimit(60);
    sf::Event event;

    sf::Texture gameover_texture;
    gameover_texture.loadFromFile("resources/back1.jpg");
    sf::Sprite gameover_texture_sprite(gameover_texture);

    Menu menu("resources/back1.jpg");
    menu.addButton(500, 200, "resources/button2.png");
    menu.addButton(500, 400, "resources/button3.png");
  
    GameOverWindow gameover_window;
    gameover_window.setPosition(300, 200);
    Game game;

    GameState game_state = GameState::ON;
    State state = State::MENU;
    MenuState menu_state = MenuState::ON;
    GameOverState gameover_state = GameOverState::ON;
    ButtonState button_state = ButtonState::NONE;

    while (window.isOpen()) {

        window.clear();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        game_state = game.getState();
        menu_state = menu.getState();
        gameover_state = gameover_window.getState();
        button_state = menu.getButtonState();

        if (game_state == GameState::MENU || gameover_state == GameOverState::MENU) {
            state = State::MENU;
            gameover_window.setState(GameOverState::ON);
            game.setState(GameState::ON);
        }
        if (gameover_state == GameOverState::OFF || button_state == ButtonState::START_GAME) {
            state = State::GAME;
            gameover_window.setState(GameOverState::ON);
            menu.setButtonState(ButtonState::NONE);
        }
        if (game_state == GameState::LOSE) {
            state = State::GAMEOVER;
            game.setState(GameState::ON);
        }

        switch (state) {
            case State::GAME:
                game.Start(window);
                break;
            case State::GAMEOVER:
                gameover_window.draw(window);
                break;
            case State::MENU:
                menu.draw(window);
                break;
        }

        window.display();
    }
}