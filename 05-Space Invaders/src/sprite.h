#pragma once
#include <iostream>
#include <raylib.h>

class Sprite
{
public:
  Sprite(Vector2 pos, std::string name);
  // ~Sprite();
  void draw();
  void move(int strideX, int strideY);
  int SPRITE_LEN = 80;
  Texture2D texture;
  Vector2 position;
  std::string name;
  void changeTexture(std::string name);

private:
  Image sprite;
};