#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
	sf::Vector2f m_position;
	sf::CircleShape m_ball_shape;

	float m_speed = 400;
	float m_direction_x = 1.0f;
	float m_direction_y = 1.0f;

public:
	Ball(float startX, float startY);

	sf::FloatRect getPosition();
	sf::CircleShape getShape();

	float getXVelocity();

	void bounceSides();
	void bounceTop();
	void hitBall();
	void update(sf::Time dt);
};

