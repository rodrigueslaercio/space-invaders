#include <iostream>
#include <SFML/Graphics.hpp>
#include "sprite.h"

using namespace sf;

int main()
{
    // Create a video mode and a window  for the game
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Space Invaders", Style::Fullscreen);

    // Textures for the game
    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background.jpg");


    while (window.isOpen())
    {
        // Handle player input
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        
        // Window related functions
        window.clear();
        window.draw(createBackground(&textureBackground));

        window.display();
    }
}
