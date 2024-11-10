#include <iostream>
#include <raylib.h>
#include "sprite.h"

int main()
{
  std::cout << "Space Invaders" << std::endl;
  const int WIN_W = 1280;
  const int WIN_H = 720;

  InitWindow(WIN_W, WIN_H, "Space Invaders");
  SetExitKey(KEY_Q);
  SetTargetFPS(60);

  Sprite *player = new Sprite("./src/sprites/ufo.png");
  Sprite *crab = new Sprite("./src/sprites/crab.png");
  Sprite *jellyfish = new Sprite("./src/sprites/jellyfish.png");
  Sprite *squid = new Sprite("./src/sprites/squid.png");

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);
    player->draw(WIN_W / 2 - 40, WIN_H - 80);
    EndDrawing();
  }

  UnloadTexture(player->texture);
  CloseWindow();

  return 0;
}