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
  int collision;
  // for (Sprite rec : collisionRecs)
  // {
    collision = CheckCollisionRecs(bullet, (Rectangle){rec.position.x, rec.position.y, (float)rec.SPRITE_LEN, (float)rec.SPRITE_LEN});
    if (collision && rec.name != "blank.png" && rec.name != "ufo.png")
    {
      std::cout << "target hit" << std::endl;
      // (&rec)->name = "blank.png";
      rec.changeTexture("./src/sprites/blank.png");
      return collision;
    }
  // }
  return false;
}

void Bullet::draw()
{
  DrawRectangle(position.x, position.y, width, height, color);
}
