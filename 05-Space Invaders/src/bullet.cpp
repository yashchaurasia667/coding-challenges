#include "bullet.h"
#include <iostream>

Bullet::Bullet(Vector2 pos, float width, float height, Color color)
{
  position = pos;
  this->color = color;
  this->width = width;
  this->height = height;
}

void Bullet::update(int stepY)
{
  position.y -= stepY;
}

void Bullet::draw()
{
  DrawRectangle(position.x, position.y, width, height, color);
}
