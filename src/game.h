#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	Game(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(const Game&) = delete;
	Game& operator=(Game&&) = delete;
	~Game() = default;

	void setState(GameState);
	GameState getState() const;

	void Start(sf::RenderWindow& sf);
};

