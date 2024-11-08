#include "snake.h"
#include <iostream>

snake::snake(Vector2 pos, Vector2 sp)
{
  segement = {pos.x, pos.y, 40, 40};
  speed = sp;
}
