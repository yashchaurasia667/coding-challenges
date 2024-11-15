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

bool Bullet::collision(Sprite &rec)
{
  Rectangle bullet = {position.x, position.y, width, height};
  // std::cout << "x = " << rec.position.x << "\ny = " << rec.position.y << std::endl;
  std::cout << rec.name << std::endl;
  int collision = CheckCollisionRecs(bullet, (Rectangle){rec.position.x, rec.position.y, (float)rec.SPRITE_LEN, (float)rec.SPRITE_LEN});
  if (collision && rec.name != "blank.png" && rec.name != "ufo.png")
  {
    std::cout << "target hit" << std::endl;
    rec.changeTexture("blank.png");
    return true;
  }
  return false;
}

void Bullet::draw()
{
  DrawRectangle(position.x, position.y, width, height, color);
}
