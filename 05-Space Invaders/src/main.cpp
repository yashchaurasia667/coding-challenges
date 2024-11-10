#include <iostream>
#include <raylib.h>

int main()
{
  std::cout << "Space Invaders" << std::endl;
  const int WIN_W = 1280;
  const int WIN_H = 720;

  InitWindow(WIN_W, WIN_H, "Space Invaders");

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(WHITE);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}