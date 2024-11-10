#include "sprite.h"

Sprite::Sprite(const char *filepath)
{
  sprite = LoadImage(filepath);
  ImageResize(&sprite, SPRITE_LEN, SPRITE_LEN);
  texture = LoadTextureFromImage(sprite);
  UnloadImage(sprite);
}

Sprite::~Sprite()
{
  UnloadTexture(texture);
}

void Sprite::draw(int x, int y)
{
  DrawTexture(texture, x, y, WHITE);
}
