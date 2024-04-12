#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <set>;

using namespace sf;

std::vector<Sprite>* enemies_aux;

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

void shootBullet(Sprite* player, std::vector<Bullet>& ammo, Texture* texture, float speed, Time dt, bool& keyWasPressed)
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
                if (bullet.sprite.getGlobalBounds().intersects(enemies_aux->at(i).getGlobalBounds()))
                {
                    bullet.active = false;
                    // Set the enemy hit off the screen
                    enemies_aux->at(i).setPosition(enemies_aux->at(i).getPosition().x, 2000);
                }
            }
        }
    }
}

void setEnemies(std::vector<Sprite>* enemies)
{
    enemies_aux = enemies;
}