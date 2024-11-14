#pragma once

#include <raylib.h>
#include <vector>

#include "sprite.h"

class Bullet
{
private:
  Color color;
  float width, height;

public:
  Vector2 position;
  Bullet(Vector2 pos, float width, float height, Color color);
  void update(int stepY);
  bool collision(Sprite &rec);
  void draw();
  // ~Bullet();
};