#include "sprite.h"

Sprite::Sprite(const char *filepath, Vector2 pos)
{
  position = pos;
  sprite = LoadImage(filepath);
  ImageResize(&sprite, SPRITE_LEN, SPRITE_LEN);
  texture = LoadTextureFromImage(sprite);
  UnloadImage(sprite);
}

// Sprite::~Sprite()
// {
// }

void Sprite::draw()
{
  DrawTexture(texture, position.x, position.y, WHITE);
}

void Sprite::move(int strideX, int strideY)
{
  if (position.x <= GetScreenWidth() - 90 && position.x >= 10)
    position.x += strideX;
  if (position.y <= GetScreenHeight() - 90 && position.x >= 10)
    position.y += strideY;
}
