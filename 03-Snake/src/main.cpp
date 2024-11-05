#include <iostream>
#include <raylib.h>

int main()
{
  // std::cout << "hello world" << std::endl;
  int winw = 800, winh = 600;
  InitWindow(winw, winh, "Snake");
  SetExitKey(KEY_Q);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}