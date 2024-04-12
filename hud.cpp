#include "hud.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Text startMessage(Font* font)
{
	Text message;
	message.setFont(*font);
	message.setString("Press Enter to start!");
	message.setFillColor(Color::Green);
	message.setCharacterSize(50);

	centerStartMessage(&message);

	return message;

}

void centerStartMessage(Text* message)
{
	// Center the message
	FloatRect startMessageRect = message->getGlobalBounds();
	message->setOrigin(startMessageRect.left + startMessageRect.width / 2.0f,
		startMessageRect.top + startMessageRect.height / 2.0f);
	message->setPosition(1920 / 2.0f, 1080 / 2.0f);
}

Text scoreMessage(Font* font)
{
	Text message;
	message.setFont(*font);
	message.setString("Score = 0");
	message.setFillColor(Color::Green);
	message.setCharacterSize(25);

	positionScoreMessage(&message);

	return message;
}


void positionScoreMessage(Text* message)
{
	// Center the message
	FloatRect startMessageRect = message->getGlobalBounds();
	message->setPosition(1750, 60);
}