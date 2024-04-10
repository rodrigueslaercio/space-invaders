#pragma once
#ifndef SPRITES_HEADER
#define SPRITES_HEADER

#include <SFML/Graphics.hpp>

using namespace sf;

Sprite createBackground(Texture *texture);

Sprite createPlayer(Texture* texture);

Sprite createBullet(Texture* texture);

#endif