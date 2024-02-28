#include "Ball.h"

Ball::Ball(float startX, float startY) {
	m_Position.x = startX;
	m_Position.y = startY;

	m_BallShape.setSize(sf::Vector2f(20, 20));
	m_BallShape.setPosition(m_Position);
}

sf::FloatRect Ball::getPosition() {
	return m_BallShape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape() {
	return m_BallShape;
}

float Ball::getXVelocity() {
	return m_DirectionX;
}

void Ball::bounceSides() {
	m_DirectionX = -m_DirectionX;
}

void Ball::bounceTop() {
	m_DirectionY = -m_DirectionY;
}

void Ball::missBottom() {
	m_Position.x = 1280 / 2;
	m_Position.y = 0;
}

void Ball::update(sf::Time dt) {
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	
	m_BallShape.setPosition(m_Position);
}

void Ball::hitBall() {
	m_DirectionY = -m_DirectionY;
}