#include "Player.h"
#include <iostream>

// Constructor: loads the texture and sets initial properties
Player::Player(const std::string& textureFile) {
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Error loading texture\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(10, 10);  // Initial position
    sprite.setScale(.9f, .9f); // Scale the sprite
}

// Handles player input to move the sprite
void Player::handleInput(float speed) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        sprite.move(0, -speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        sprite.move(0, speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        sprite.move(-speed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        sprite.move(speed, 0);
    }
}

// Draws the player sprite to the window
void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
