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
  position.x += strideX;
  position.y += strideY;

  if (position.x < 0)
    position.x = 0;
  else if (position.x > GetScreenWidth() - SPRITE_LEN)
    position.x = GetScreenWidth() - SPRITE_LEN;

  if (position.y < 0)
    position.y = 0;
  else if (position.y > GetScreenHeight() - SPRITE_LEN)
    position.y = GetScreenHeight() - SPRITE_LEN;
  // std::cout << "screenwidth = " << GetScreenWidth() << std::endl;
}
