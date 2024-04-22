#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"

enum class GameState { ON, LOSE, MENU };

class Game
{
private:
	sf::Texture game_texture;
	sf::Sprite game_sprite;
	GameState game_state = GameState::ON;
public:
	Game();
	void setState(GameState);
	GameState getState() const;

	void Start(sf::RenderWindow& sf);
};

