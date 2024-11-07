#include "snake.h"

snake::snake(Vector2 pos, int sX, int sY)
{
  // position = pos;
  segement = {pos.x, pos.y, 40, 40};
  speedX = 1;
  speedY = 0;
}
