#include <iostream>
#include <SFML/Graphics.hpp>
#include "sprite.h"
#include "hud.h"
#include "player.h"

using namespace sf;

int main()
{
    // Create a video mode and a window  for the game
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Space Invaders", Style::Fullscreen);

    // Textures for the background
    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background.jpg");

    // Texture and sprite for the player
    Texture texturePlayer;
    texturePlayer.loadFromFile("graphics/ship.png");
    Sprite player = createPlayer(&texturePlayer);

    // Boolean to check if the game is paused
    bool paused = true;

    // Clock to count the frames
    Clock clock;

    Font font; 
    font.loadFromFile("fonts/airstrike.ttf");

    // Call the function to create the message
    Text message = startMessage(&font);
        
    while (window.isOpen())
    {
        // Handle player input
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Enter))
        {
            paused = false;
        }


        // * Update the scenes of the game *
        if (!paused)
        {
            // Delta time timing each frame
            Time dt = clock.restart();

            // Function to move the player left & right
            move(&player, 0.5f);
        }
        
        // Clear each frame 
        window.clear();

        //* Draw in the screen *
        window.draw(createBackground(&textureBackground));
        window.draw(player);
        if (paused) window.draw(message);

        window.display();
    }
}
