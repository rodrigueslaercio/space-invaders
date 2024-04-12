#pragma once
#ifndef HUD_HEADER
#define HUD_HEADER

#include <SFML/Graphics.hpp>

using namespace sf;

Text startMessage(Font* font);

void centerStartMessage(Text* message);

Text scoreMessage(Font* font);

void positionScoreMessage(Text* message);

#endif

