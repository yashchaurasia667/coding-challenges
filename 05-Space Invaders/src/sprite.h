#pragma once
#include <iostream>
#include <raylib.h>

class Sprite
{
public:
  Sprite(const char *filepath, Vector2 pos);
  // ~Sprite();
  void draw();
  void move(int strideX, int strideY);
  int SPRITE_LEN = 80;
  Texture2D texture;
  Vector2 position;

private:
  Image sprite;
};