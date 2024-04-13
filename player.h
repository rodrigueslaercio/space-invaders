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

struct Explosion {
	Sprite sprite;
	bool active;
	Clock animationClock;
};

void shootBullet(Sprite* player, std::vector<Bullet>& ammo, Texture* texture, float speed, Time dt, bool& keyWasPressed,
	Texture* textureExplosion, IntRect* rectExplosion, std::vector<Explosion>* explosions);

void setEnemies(std::vector<Sprite>* enemies);

int getScore();

void setScore(int value);

bool gameOver(Sprite* player);

#endif