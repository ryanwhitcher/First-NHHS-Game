#include <SFML/Graphics.hpp>
#include "Player.h"


void handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Application");
    window.setFramerateLimit(60);

    Player player("../src/assets/Red_Eyegore_Model.png");
    float speed = 5.0f;

    while (window.isOpen()) {
        handleEvents(window);  // Separate event handling

        player.handleInput(speed);  // Update player movement based on input

        window.clear(sf::Color(255, 255, 0));  // Clear with yellow background
        player.draw(window);  // Draw the player
        window.display();
    }

    return 0;
}
