#pragma once
#include <raylib.h>

class Sprite
{
public:
  Sprite(const char *filepath);
  ~Sprite();
  void draw(int x, int y);
  int SPRITE_LEN = 80;
  Texture2D texture;

private:
  Image sprite;
};