#include <iostream>
#include <vector>
#include "snake.h"
#include <raylib.h>

#define FPS 10
#define SPEED 40

void draw(std::vector<snake> body)
{
  for (size_t i = 0; i < body.size(); i++)
    DrawRectangle(body[i].position.x, body[i].position.y, body[i].width, body[i].width, WHITE);
}

std::vector<snake> update(std::vector<snake> body)
{
  for (size_t i = 0; i < body.size(); i++)
  {
    body[i].position.x += (SPEED * body[i].speedX);
    body[i].position.y += (SPEED * body[i].speedY);
  }
  return body;
}

int main()
{
  int winw = 800, winh = 600;
  InitWindow(winw, winh, "Snake");
  SetExitKey(KEY_Q);
  SetTargetFPS(FPS);

  std::vector<snake> body;
  snake *segment = new snake((Vector2){100, 100});
  body.push_back(*segment);

  while (!WindowShouldClose())
  {
    if (winw != GetScreenWidth() || winh != GetScreenHeight())
    {
      winw = GetScreenWidth();
      winh = GetScreenHeight();
    }

    BeginDrawing();
    ClearBackground(BLACK);
    draw(body);
    body = update(body);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}