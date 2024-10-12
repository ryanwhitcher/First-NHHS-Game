#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <string>

class Player {
public:
    // Constructor
    Player(const std::string& textureFile);

    // Handles keyboard input to move the sprite
    void handleInput(float speed);

    // Draws the player sprite to the window
    void draw(sf::RenderWindow& window);

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif
