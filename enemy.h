#pragma once
#ifndef ENEMY_HEADER
#define ENEMY_HEADER

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

std::vector<Sprite> createEnemies(Texture* texture);

void moveEnemies(std::vector<Sprite>* enemies, Time dt);

bool areEnemiesOffScreen(std::vector<Sprite>* enemies);


#endif