#pragma once
#include <raylib.h>

class snake
{
public:
  // Vector2 position;
  Rectangle segement;
  int speedX, speedY;
  snake(Vector2 pos, int sX = 1, int sY = 0);
};