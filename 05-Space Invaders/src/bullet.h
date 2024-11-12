#pragma once

#include <raylib.h>

class Bullet
{
private:
  Vector2 position;
  Color color;
  float width, height;

public:
  Bullet(Vector2 pos, float width, float height, Color color);
  void update(int stepY);
  void draw();
  // ~Bullet();
};