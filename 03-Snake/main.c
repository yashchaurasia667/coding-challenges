#include <raylib.h>
#include <stdio.h>

struct segment {
  int x;
  int y;
};

typedef struct segment Segment;

void DrawGrid2D(int spacing, Color color) {
  int winW = GetScreenWidth();
  int winH = GetScreenHeight();

  for (int x = 0; x < winW; x += spacing) {
    DrawLine(x, 0, x, winH, color);
  }

  for (int y = 0; y < winH; y += spacing) {
    DrawLine(0, y, winW, y, color);
  }
}

int main() {
  int winw = 800;
  int winh = 600;

  InitWindow(winw, winh, "Snake");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawGrid2D(50, WHITE);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
