#include "Player.h"  // We include this to declare the Player class methods, allowing separation of implementation and declaration
#include <iostream>  // We include this to enable output to the console, useful for error handling and debugging

/*
Player constructor initializes the player object with a texture file.
Using a constructor to load the texture ensures the Player object is fully initialized with the required assets before use.
*/
Player::Player(const std::string& textureFile) {
    /*
    'if (!texture.loadFromFile(textureFile))' checks whether the texture was successfully loaded.
    This prevents issues down the line by verifying early that the file exists and can be used.
    */
    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Error loading texture\n";  // Output an error message if loading fails, useful for debugging
    }

    // Associating the texture with the sprite here ensures the sprite knows what image to display
    sprite.setTexture(texture);

    /*
    The initial position of the sprite is set using setPosition. We choose a default position here
    so the sprite starts from a known, consistent point, making testing and development predictable.
    */
    sprite.setPosition(10, 10);  // Start the sprite at coordinates (10, 10)

    // Scaling the sprite to 90% of its original size provides flexibility for adjusting visual proportions
    sprite.setScale(.9f, .9f);  // Scale down the sprite to 90% in both x and y directions
}

/*
This function handles player input using the SFML keyboard interface.
It's separated from other logic to keep responsibilities distinct, making the code more readable and maintainable.
*/
void Player::handleInput(float speed) {
    /*
    Using 'sf::Keyboard::isKeyPressed' allows us to detect if a key is being held down, which is more suitable for continuous movement.
    This approach provides real-time responsiveness without needing to manage key press events manually.
    */
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        sprite.move(0, -speed);  // Move the sprite upwards by 'speed' units
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        sprite.move(0, speed);  // Move the sprite downwards by 'speed' units
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        sprite.move(-speed, 0);  // Move the sprite to the left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        sprite.move(speed, 0);  // Move the sprite to the right
    }
}

/*
The draw function is kept separate to follow the principle of single responsibility, ensuring the Player class is only responsible for its own rendering logic.
This also allows for more flexible rendering logic in the future without touching the core game loop.
*/
void Player::draw(sf::RenderWindow& window) {
    /*
    'window.draw(sprite)' directly draws the sprite to the window. By passing the window by reference,
    we avoid unnecessary copying and ensure the Player object modifies the actual window used in the main loop.
    */
    window.draw(sprite);  // Render the player sprite onto the window
}
