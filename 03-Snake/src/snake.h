#pragma once
#include <raylib.h>

class snake
{
public:
  Rectangle segement;
  Vector2 speed;
  snake(Vector2 pos, Vector2 sp = {1, 0});
};