#include <iostream>
#include <vector>
#include <raylib.h>
#include "sprite.h"

void handleInput(Sprite *sprite)
{
  if (IsKeyPressed(KEY_RIGHT))
    sprite->move(80, 0);
  else if (IsKeyPressed(KEY_LEFT))
    sprite->move(-80, 0);
}

int main()
{
  std::cout << "Space Invaders" << std::endl;
  const int WIN_W = 1280;
  const int WIN_H = 720;

  InitWindow(WIN_W, WIN_H, "Space Invaders");
  SetExitKey(KEY_Q);
  SetTargetFPS(60);

  Vector2 pos = {WIN_W / 2 - 40, WIN_H - 80};
  Sprite *player = new Sprite("./src/sprites/ufo.png", pos);

  std::vector<Sprite> enemies;
  enemies.push_back(*(new Sprite("./src/sprites/crab.png", {10, 10})));
  enemies.push_back(*(new Sprite("./src/sprites/jellyfish.png", {100, 10})));
  enemies.push_back(*(new Sprite("./src/sprites/squid.png", {200, 10})));

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);
    for (Sprite enemy : enemies)
      enemy.draw();
    player->draw();
    handleInput(player);
    EndDrawing();
  }

  for(Sprite enemy: enemies)
    UnloadTexture(enemy.texture);
  UnloadTexture(player->texture);
  CloseWindow();

  return 0;
}