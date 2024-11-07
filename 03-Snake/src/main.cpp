#include <iostream>
#include <vector>
#include "snake.h"
#include <raylib.h>

#define FPS 10
#define SPEED 40

void draw(std::vector<snake> body)
{
  for (size_t i = 0; i < body.size(); i++)
    DrawRectangleRec(body[i].segement, WHITE);
}

std::vector<snake> update(std::vector<snake> body)
{
  for (size_t i = 0; i < body.size(); i++)
  {
    if (i != 0)
    {
      body[i] = body[i - 1];
      body[i].segement.x -= (40 * body[i].speedX);
      body[i].segement.y -= (40 * body[i].speedY);
    }
    else
    {
      body[i].segement.x += (SPEED * body[i].speedX);
      body[i].segement.y += (SPEED * body[i].speedY);
    }
  }
  return body;
}

Vector2 renderFood(int width, int height)
{
  float x = rand() % (width - 30);
  float y = rand() % (height - 30);

  // std::cout << "x: " << x << "\ny: " << y << std::endl;
  return (Vector2){x, y};
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

snake add_segment(snake last)
{
  snake *tail = new snake((Vector2){last.segement.x + (40 * last.speedX), last.segement.y + (40 * last.speedY)});
  return *tail;
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
  Rectangle food = {foodPos.x, foodPos.y, 30, 30};
  bool eaten = false;

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

    if (eaten)
    {
      eaten = false;
      foodPos = renderFood(winw, winh);
      food = {foodPos.x, foodPos.y, 30, 30};
      body.push_back(add_segment(body[body.size() - 1]));
    }
    DrawRectangleRec(food, RED);

    draw(body);
    body = update(body);

    eaten = CheckCollisionRecs(body[0].segement, food);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}