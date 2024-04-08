#include "sprite.h"

using namespace sf;

Sprite createBackground(Texture* texture)
{
    Sprite spriteBackground;
    spriteBackground.setTexture(*texture);
    spriteBackground.setPosition(0, 0);

    return spriteBackground;
}

Sprite createPlayer(Texture* texture)
{
    Sprite spritePlayer;
    spritePlayer.setTexture(*texture);
    spritePlayer.setPosition(1920 / 2, 1000);

    return spritePlayer;
}