#include "sprite.h"

using namespace sf;

Sprite createBackground(Texture* texture)
{
    Sprite spriteBackground;
    spriteBackground.setTexture(*texture);
    spriteBackground.setPosition(0, 0);

    return spriteBackground;
}