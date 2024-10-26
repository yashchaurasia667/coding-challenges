#include <raylib.h>
#include <stdio.h>

int main() {
  int winw = 800;
  int winh = 600;
  InitWindow(winw, winh, "Snake");
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
