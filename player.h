#pragma once
#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

void move(Sprite* player, float speed);

bool isOutOfBoundsLeft(Sprite player);

bool isOutOfBoundsRight(Sprite player);

struct Bullet {
	Sprite sprite;
	bool active;
};

void shootBullet(Sprite* player, std::vector<Bullet>& ammo, Texture* texture, float speed, Time dt, bool& keyWasPressed);

#endif