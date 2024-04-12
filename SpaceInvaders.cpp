#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "sprite.h"
#include "hud.h"
#include "player.h"
#include "enemy.h"

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


    // Texture for enemies
    Texture textureEnemy;
    textureEnemy.loadFromFile("graphics/enemy_ship.png");

    // Vector containing the enemies
    std::vector<Sprite> enemies = createEnemies(&textureEnemy);

    // Texture and sprite for the bullet
    Texture textureBullet;
    textureBullet.loadFromFile("graphics/bullet.png");
    Sprite bullet = createBullet(&textureBullet);

    // Texture and Rect of the explosion
    Texture textureExplosion;
    textureExplosion.loadFromFile("graphics/explosion.png");
    IntRect rectExplosion(0, 0, 64, 64);

    // Num of frames and its width of each sprite in the sheet
    const int frameWidth = 64;
    const int numFrames = 16;

    // Boolean to check if the game is paused
    bool paused = true;

    // Clock to count the frames
    Clock clock;

    Font font; 
    font.loadFromFile("fonts/airstrike.ttf");

    // Call the function to create the message
    Text message = startMessage(&font);
    Text scoreText = scoreMessage(&font);

    // Ammo
    std::vector<Bullet> ammo;

    // Explosions
    std::vector<Explosion> explosions;
        
    bool keyWasPressed;

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            // Check if the X key was released
            if (event.type == Event::KeyReleased && !paused)
            {
                keyWasPressed = false;
            }
        }

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

            // Function to move the enemies ships
            moveEnemies(&enemies, dt);

            // Function that sets the enemy vector in a var aux for collision detection
            setEnemies(&enemies);

            // Change the score text
            std::stringstream ss;
            ss << "Score = " << getScore();
            scoreText.setString(ss.str());

            // Recreate the enemies when they are off the screen
            if (areEnemiesOffScreen(&enemies))
            {
                enemies = createEnemies(&textureEnemy);
            }
           
            // Shoot the bullet
            shootBullet(&player, ammo, &textureBullet, 300, dt, keyWasPressed, &textureExplosion, &rectExplosion, &explosions);


            // Animation explosion sheet logic
            for (auto& explosion : explosions) 
            {
                if (explosion.active) 
                {
                    if (explosion.animationClock.getElapsedTime().asSeconds() > 0.06f) 
                    {
                        // Advances each frame of the sheet
                        rectExplosion.left += frameWidth;
                        if (rectExplosion.left >= frameWidth * numFrames) 
                        {
                            rectExplosion.left = 0;
                            explosion.active = false;
                        }
                        explosion.sprite.setTextureRect(rectExplosion);

                    }
                }
                else
                {
                    explosion.animationClock.restart();
                }
            }

        }
        
        // Clear each frame 
        window.clear();

        //* Draw in the screen *
        window.draw(createBackground(&textureBackground));

        window.draw(player);

        if (paused) window.draw(message);
        if (!paused) window.draw(scoreText);

        for (auto& enemy : enemies)
            window.draw(enemy);

        for (auto& bullet : ammo)
        {
            if (bullet.active)
            {
                window.draw(bullet.sprite);
            }
        }

        for (auto& explosion : explosions)
        {
            if (explosion.active)
            {
                window.draw(explosion.sprite);
            }
        }

        window.display();
    }
}
