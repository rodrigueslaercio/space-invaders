#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <SFML/Graphics.hpp>

using namespace sf;

void move(Sprite* player, float speed);

bool isOutOfBoundsLeft(Sprite player);

bool isOutOfBoundsRight(Sprite player);

#endif