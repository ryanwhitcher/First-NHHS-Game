#ifndef PLAYER_H  // Header guard to prevent multiple inclusions of the same file
#define PLAYER_H  // 'PLAYER_H' is a unique identifier for this header file

#include <SFML/Graphics.hpp>  // Include SFML graphics components needed for textures and sprites
#include <string>  // Include the string library to handle file paths and other string operations

/*
The Player class encapsulates all logic related to the player entity.
This allows the game to manage multiple aspects of the player (movement, rendering) in a centralized and reusable manner.
*/
class Player {
public:
    // Constructor is declared public so that Player objects can be created in other parts of the program
    Player(const std::string& textureFile);

    /*
    The handleInput function is declared here to allow movement control outside the class definition.
    It is public so other parts of the program can call it when they need to update player movement.
    */
    void handleInput(float speed);

    // The draw function is responsible for rendering the player, so it's public for access from the main game loop
    void draw(sf::RenderWindow& window);

private:
    /*
    The texture member holds the image data for the player's visual appearance.
    It is kept private to enforce encapsulation, ensuring that only the Player class can modify it directly.
    */
    sf::Texture texture;

    /*
    The sprite represents the player object on the screen.
    Keeping it private maintains strict control over how the sprite is manipulated,
    enforcing the idea that the Player class is responsible for its own rendering behavior.
    */
    sf::Sprite sprite;
};

#endif  // End of the header guard
