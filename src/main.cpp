#include <SFML/Graphics.hpp>
#include <cmath>

// Convert degrees to radians
const float PI = 3.14159265f;
float degToRad(float degrees) {
    return degrees * (PI / 180);
}

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Enter the Gungeon Style");

    // Create a player rectangle to represent the character
    sf::RectangleShape player(sf::Vector2f(40, 40));
    player.setFillColor(sf::Color::Blue);
    player.setOrigin(20, 20); // Set the origin to the center for rotation
    player.setPosition(400, 300); // Start in the center of the window

    float speed = 200.0f;   // Player movement speed
    float rotationSpeed = 180.0f;  // Degrees per second

    sf::Clock clock; // For keeping track of frame time

    // Game loop
    while (window.isOpen()) {
        sf::Time dt = clock.restart();
        float deltaTime = dt.asSeconds();

        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Player movement
        sf::Vector2f movement(0, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            movement.y -= speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            movement.y += speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            movement.x -= speed * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            movement.x += speed * deltaTime;

        // Normalize diagonal movement
        if (movement.x != 0 && movement.y != 0) {
            movement *= 1.0f / std::sqrt(2.0f);
        }

        player.move(movement);

        // Player rotation (aiming using the mouse)
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f playerPos = player.getPosition();

        // Calculate angle between player and mouse position
        float dx = mousePos.x - playerPos.x;
        float dy = mousePos.y - playerPos.y;
        float angle = std::atan2(dy, dx) * 180 / PI; // Get angle in degrees

        player.setRotation(angle);

        // Rendering
        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}
//this is how the camera and player movement will proceed as, thanks chat!