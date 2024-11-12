#include <iostream>
#include <vector>
#include <raylib.h>
#include "sprite.h"

#define SPRITE_LEN 80

const int WIN_W = 1280;
const int WIN_H = 720;
std::vector<std::string> enemies = {"crab.png", "jellyfish.png", "squid.png"};

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

int main()
{
  srand(time(0));

  std::cout << "Space Invaders" << std::endl;

  InitWindow(WIN_W, WIN_H, "Space Invaders");
  SetExitKey(KEY_Q);
  SetTargetFPS(60);

  Vector2 pos = {WIN_W / 2, WIN_H - 80};
  Sprite *player = new Sprite("./src/sprites/ufo.png", pos);

  // enemies.push_back(*(new Sprite("./src/sprites/crab.png", {0, 10})));
  // enemies.push_back(*(new Sprite("./src/sprites/jellyfish.png", {80, 10})));
  // enemies.push_back(*(new Sprite("./src/sprites/squid.png", {160, 10})));

  std::vector<std::vector<Sprite>> rows;
  for (int i = 0; i < 3; i++)
    rows.push_back(createRow(i));

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);
    for (std::vector row : rows)
      for (Sprite enemy : row)
        enemy.draw();
    handleInput(player);
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