#include <raylib.h>

int main()
{
  const int WIDTH = 800;
  const int HEIGHT = 600;
  InitWindow(WIDTH, HEIGHT, "Mitosis simulation");
  while(!WindowShouldClose()) {
    BeginDrawing();
    EndDrawing();
  }
  CloseWindow();
  return 0;
}