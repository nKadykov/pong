#include "paddle.h"

Paddle::Paddle(float startX, float startY) {
	m_position.x = startX;
	m_position.y = startY;

	m_shape.setSize(sf::Vector2f(100, 12));
	m_shape.setFillColor(sf::Color::Blue);
	m_shape.setOutlineColor(sf::Color::White);
	m_shape.setOutlineThickness(2);

	m_shape.setPosition(m_position);
}

sf::FloatRect Paddle::getPosition() {
	return m_shape.getGlobalBounds();
}

sf::RectangleShape Paddle::getShape() {
	return m_shape;
}

void Paddle::moveLeft() {
	m_moving_left = true;
}

void Paddle::moveRight() {
	m_moving_right = true;
}

void Paddle::stopLeft() {
	m_moving_left = false;
}

void Paddle::stopRight() {
	m_moving_right = false;
}

void Paddle::update(sf::Time dt) {
	if (m_moving_left) {
		m_position.x -= m_speed * dt.asSeconds();
	}
	if (m_moving_right) {
		m_position.x += m_speed * dt.asSeconds();
	}
	if (m_position.x < 0) {
		m_position.x = 0;
	}
	if (m_position.x > 1180) {
		m_position.x = 1180;
	}
	m_shape.setPosition(m_position);
}