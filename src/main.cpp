#include <SFML/Graphics.hpp>  // Access SFML's 2D graphics functionalities
#include "Player.h"  // Include the Player class for managing player-related behavior

/*
'sf::RenderWindow& window' means we are passing a reference to an existing sf::RenderWindow object.

- 'sf::' specifies that RenderWindow belongs to the SFML namespace.
- 'RenderWindow' is the class responsible for managing the window itself (rendering, displaying, event handling).
- The '&' means we are passing the window by reference, not by value. This allows us to avoid copying the entire window object, which would be inefficient.
- Passing by reference also means we are directly working with the same window object, allowing changes (e.g., closing it) to persist outside this function.
*/
void handleEvents(sf::RenderWindow& window) {
    sf::Event event;  // Creates an event object to capture user interactions
    while (window.pollEvent(event)) {  // Polls for events and stores them in 'event'
        if (event.type == sf::Event::Closed)  // If the event is a 'close window' request
            window.close();  // Close the window by modifying the original window object (since it's a reference)
    }
}

int main() {
    /*
    Here we are creating an sf::RenderWindow object (without reference).
    This window manages drawing and events for the application.
    */
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Application");

    window.setFramerateLimit(60);  // We directly manipulate the 'window' object to limit its framerate

    Player player("../src/assets/Red_Eyegore_Model.png");  // Initialize a player with an image file path
    float speed = 5.0f;

    while (window.isOpen()) {  // As long as the window object hasn't been closed, keep running the game loop
        handleEvents(window);  // Pass 'window' by reference to 'handleEvents', so the same window object is used

        player.handleInput(speed);  // Player input affects movement

        window.clear(sf::Color(255, 255, 0));  // Clear the window with a yellow background

        player.draw(window);  // Pass 'window' by reference to the player's draw function, which renders on the same window

        window.display();  // Present the rendered frame to the screen
    }

    return 0;  // Exit the program
}
