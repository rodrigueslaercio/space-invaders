#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <set>;

using namespace sf;

std::vector<Sprite>* enemies_aux;
float enemyCurrentX = 0.0f;
float enemyCurrentY = 0.0f;
int score = 0;

void move(Sprite* player, float speed)
{
    float x = player->getPosition().x;
    bool isLeftPressed = false;
    bool isRightPressed = false;

    if (Keyboard::isKeyPressed(Keyboard::Left)) isLeftPressed = true;
    if (Keyboard::isKeyPressed(Keyboard::Right)) isRightPressed = true;

    if (isLeftPressed && !isOutOfBoundsLeft(*player)) x -= speed;
    if (isRightPressed && !isOutOfBoundsRight(*player)) x += speed;

    player->setPosition(x, player->getPosition().y);
}

bool isOutOfBoundsLeft(Sprite player)
{
    if (player.getPosition().x <= 0) return true;

    return false;
}

bool isOutOfBoundsRight(Sprite player)
{
    float windowWidth = 1920;
    float playerWidth = player.getGlobalBounds().width;

    if (player.getPosition().x + playerWidth >= windowWidth) return true;

    return false;
}

void shootBullet(Sprite* player, std::vector<Bullet>& ammo, Texture* texture, float speed, Time dt, bool& keyWasPressed,
    Texture* textureExplosion, IntRect* rectExplosion, std::vector<Explosion>* explosions)
{
    float playerX = player->getPosition().x;
    float playerY = player->getPosition().y;

    bool keyPressedNow = Keyboard::isKeyPressed(Keyboard::X);

    // Check if the key is pressed now
    if (keyPressedNow && !keyWasPressed)
    {
        Bullet newBullet;
        newBullet.sprite.setTexture(*texture);
        newBullet.sprite.setPosition(playerX, playerY - player->getGlobalBounds().height * 1.5);
        newBullet.active = true;
        ammo.push_back(newBullet);
    }

    keyWasPressed = keyPressedNow;

    for (auto& bullet : ammo)
    {
        if (bullet.active)
        {
            bullet.sprite.setPosition(bullet.sprite.getPosition().x, bullet.sprite.getPosition().y - (speed * dt.asSeconds()));

            // Collision detection
            for (int i = 0; i < enemies_aux->size(); i++)
            {
                enemyCurrentX = enemies_aux->at(i).getPosition().x;
                enemyCurrentY = enemies_aux->at(i).getPosition().y;

                if (bullet.sprite.getGlobalBounds().intersects(enemies_aux->at(i).getGlobalBounds()))
                {
                    // Create a new explosion for each collision
                    Explosion newExplosion;
                    newExplosion.sprite.setTexture(*textureExplosion);
                    newExplosion.sprite.setTextureRect(*rectExplosion);
                    newExplosion.sprite.setPosition(enemyCurrentX - newExplosion.sprite.getGlobalBounds().width, enemyCurrentY);
                    newExplosion.active = true;
                    explosions->push_back(newExplosion);

                    // Turn off the bullet drawing
                    bullet.active = false;
                    // Set the enemy hit off the screen
                    enemies_aux->at(i).setPosition(enemies_aux->at(i).getPosition().x, 2000);

                    score++;
                }

                // Turn off the bullet drawing if it goes of the Y axis
                if (bullet.sprite.getPosition().y <= 0)
                {
                    bullet.active = false;
                }
            }
        }
    }
}

void setEnemies(std::vector<Sprite>* enemies)
{
    enemies_aux = enemies;
}

int getScore()
{
    return score;
}

void setScore(int value)
{
    score = value;
}

bool gameOver(Sprite* player)
{
    for (int i = 0; i < enemies_aux->size(); i++)
    {
        // Check for collision between the player and the enemies
        if (player->getGlobalBounds().intersects(enemies_aux->at(i).getGlobalBounds()))
        {
            return true;
        }
    }

    return false;
}