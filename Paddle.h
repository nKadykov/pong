#pragma once
#include <SFML/graphics.hpp>

class Paddle
{
	sf::RectangleShape m_shape;
	sf::Vector2f m_position;
	float m_speed = 1500.0f;

	bool m_moving_left = false;
	bool m_moving_right = false;

public:
	Paddle() = default;
	Paddle(float startX, float startY);
	Paddle(const Paddle&) = delete;
	Paddle(Paddle&&) = delete;
	Paddle& operator=(const Paddle&) = delete;
	Paddle& operator=(Paddle&&) = delete;
	~Paddle() = default;

	sf::RectangleShape getShape();
	sf::FloatRect getPosition();

	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();

	void update(sf::Time dt);
};

