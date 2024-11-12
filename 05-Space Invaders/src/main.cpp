#include <iostream>
#include <vector>
#include <raylib.h>
#include "sprite.h"
#include "bullet.h"

#define SPRITE_LEN 80

const int WIN_W = 1280;
const int WIN_H = 720;
std::vector<std::string> enemies = {"crab.png", "jellyfish.png", "squid.png"};

Bullet shoot(int x, int y);

void handleInput(Sprite *sprite)
{
  if (IsKeyPressed(KEY_RIGHT))
    sprite->move(80, 0);
  else if (IsKeyPressed(KEY_LEFT))
    sprite->move(-80, 0);
}

std::vector<Sprite> createRow(int y)
{
  std::vector<Sprite> row;
  for (int i = 0; i < WIN_W / SPRITE_LEN; i++)
  {
    int choice = rand() % enemies.size();
    std::string path = "./src/sprites/" + enemies[choice];
    const char *filepath = path.c_str();
    Sprite *s = new Sprite(filepath, {i * SPRITE_LEN, y * SPRITE_LEN});
    row.push_back(*s);
  }
  return row;
}

Bullet shoot(int x, int y)
{
  // std::cout << "shot" << std::endl;
  Bullet *b = new Bullet({x + SPRITE_LEN / 2, y + SPRITE_LEN / 2}, 10, 15, YELLOW);
  return *b;
}

int main()
{
  srand(time(0));

  std::cout << "Space Invaders" << std::endl;

  InitWindow(WIN_W, WIN_H, "Space Invaders");
  SetWindowState(FLAG_WINDOW_RESIZABLE);
  SetWindowState(FLAG_WINDOW_UNDECORATED);
  SetExitKey(KEY_Q);
  SetTargetFPS(60);

  Vector2 pos = {WIN_W / 2, WIN_H - 80};
  Sprite *player = new Sprite("./src/sprites/ufo.png", pos);

  std::vector<std::vector<Sprite>> rows;
  rows.push_back(createRow(0));

  std::vector<Bullet> bullets;

  time_t start = time(0);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);
    for (std::vector row : rows)
      for (Sprite enemy : row)
        enemy.draw();

    handleInput(player);
    if (IsKeyPressed(KEY_SPACE))
      bullets.push_back(shoot(player->position.x, player->position.y));

    for (Bullet &bullet : bullets)
    {
      bullet.draw();
      if (time(0) - start > 0.3) {
        start = time(0);
        bullet.update(SPRITE_LEN);
      }
    }

    player->draw();
    EndDrawing();
  }

  for (std::vector row : rows)
    for (Sprite enemy : row)
      UnloadTexture(enemy.texture);

  UnloadTexture(player->texture);
  CloseWindow();

  return 0;
}