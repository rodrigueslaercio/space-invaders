#include "player.h"
#include <SFML/Graphics.hpp>

using namespace sf;

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