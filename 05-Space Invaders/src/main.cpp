#include <iostream>
#include <vector>
#include <chrono>
#include <raylib.h>

#include "sprite.h"
#include "bullet.h"

#define SPRITE_LEN 80

const int WIN_W = 1280;
const int WIN_H = 720;
std::vector<std::string> enemies = {"crab.png", "jellyfish.png", "squid.png"};

Bullet shoot(int x, int y)
{
  Bullet *b = new Bullet({x + SPRITE_LEN / 2, y + SPRITE_LEN / 2}, 10, 15, YELLOW);
  return *b;
}

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
    Sprite *s = new Sprite({(int)(i * SPRITE_LEN), (int)(y * SPRITE_LEN)}, enemies[choice]);
    row.push_back(*s);
  }
  return row;
}

int main()
{
  srand(time(0));
  auto start = std::chrono::high_resolution_clock::now();

  std::cout << "Space Invaders" << std::endl;

  InitWindow(WIN_W, WIN_H, "Space Invaders");
  SetWindowState(FLAG_WINDOW_RESIZABLE);
  SetWindowState(FLAG_WINDOW_UNDECORATED);
  SetExitKey(KEY_Q);
  SetTargetFPS(60);

  Vector2 pos = {WIN_W / 2, WIN_H - 80};
  Sprite *player = new Sprite(pos, "ufo.png");

  std::vector<std::vector<Sprite>> rows;
  rows.push_back(createRow(0));

  std::vector<Bullet> bullets;

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
      bullet.draw();

    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = now - start;

    if (duration.count() > 0.5)
    {
      for (Bullet &bullet : bullets)
      {
        std::vector<Sprite> collisionrec;
        int col = (bullet.position.x - 40) / 80;

        // std::cout << col << std::endl;
        bullet.update(SPRITE_LEN);
        for (size_t i = 0; i < rows.size(); i++)
          bullet.collision(rows[i][col]);
      }
      start = std::chrono::high_resolution_clock::now();
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