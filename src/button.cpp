#include "button.h"

Button::Button(int buttonX, int buttonY, std::string filename) {
	if (!m_texture.loadFromFile(filename)) {
		exit(1);
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(buttonX, buttonY);
}

void Button::setButtonPosition(int buttonX, int buttonY) {
	m_sprite.setPosition(buttonX, buttonY);
}

void Button::draw(sf::RenderWindow& window) {
	window.draw(m_sprite);
}