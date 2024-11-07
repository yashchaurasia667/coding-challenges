#include <iostream>
#include <vector>
#include "snake.h"
#include <raylib.h>

#define FPS 5
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

Vector2 renderFood(int width, int height)
{
  return (Vector2){
      rand() % width,
      rand() % height,
  };
}

snake handleInput(key_t key, snake head)
{
  if (key == KEY_UP && head.speedY != 1)
  {
    head.speedY = -1;
    head.speedX = 0;
  }
  if (key == KEY_DOWN && head.speedY != -1)
  {
    head.speedY = 1;
    head.speedX = 0;
  }
  if (key == KEY_LEFT && head.speedX != 1)
  {
    head.speedX = -1;
    head.speedY = 0;
  }
  if (key == KEY_RIGHT && head.speedX != -1)
  {
    head.speedX = 1;
    head.speedY = 0;
  }

  return head;
}

int main()
{
  int winw = 800, winh = 600;
  InitWindow(winw, winh, "Snake");
  SetExitKey(KEY_Q);
  SetTargetFPS(FPS);

  srand(time(0));

  std::vector<snake> body;
  snake *segment = new snake((Vector2){100, 100});
  body.push_back(*segment);

  Vector2 foodPos = renderFood(winw, winh);

  while (!WindowShouldClose())
  {
    if (winw != GetScreenWidth() || winh != GetScreenHeight())
    {
      winw = GetScreenWidth();
      winh = GetScreenHeight();
    }

    body[0] = handleInput(GetKeyPressed(), body[0]);

    BeginDrawing();
    ClearBackground(BLACK);

    if (foodPos.x == NULL)
      foodPos = renderFood(winw, winh);
    DrawRectangle(foodPos.x, foodPos.y, 30, 30, RED);

    draw(body);
    body = update(body);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}