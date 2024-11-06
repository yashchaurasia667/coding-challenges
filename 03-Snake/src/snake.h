#pragma once
#include <raylib.h>

class snake
{
public:
  Vector2 position;
  int speedX, speedY, width;
  snake(Vector2 pos);
};