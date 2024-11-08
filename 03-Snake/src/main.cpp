#include <iostream>
#include <vector>
#include "snake.h"
#include <raylib.h>

#define FPS 10
#define SPEED 40

void draw(std::vector<snake> body)
{
  Color snakeColor = GREEN;
  for (size_t i = 0; i < body.size(); i++)
  {

    DrawRectangleRec(body[i].segement, snakeColor);
    snakeColor = WHITE;
  }
}

std::vector<snake> update(std::vector<snake> body)
{
  for (size_t i = 0; i < body.size(); i++)
  {
    float px, py;
    if (i != 0)
    {
      int tx = body[i].segement.x;
      int ty = body[i].segement.y;

      body[i] = body[i - 1];
      body[i].segement.x = px;
      body[i].segement.y = py;

      px = tx;
      py = ty;
    }
    else
    {
      px = body[i].segement.x;
      py = body[i].segement.y;

      body[i].segement.x += (SPEED * body[i].speed.x);
      body[i].segement.y += (SPEED * body[i].speed.y);
    }
    if (body[i].segement.x > GetScreenWidth())
      body[i].segement.x = 0;
    else if (body[i].segement.x < 0)
      body[i].segement.x = GetScreenWidth() - 40;
    if (body[i].segement.y > GetScreenHeight())
      body[i].segement.y = 0;
    else if (body[i].segement.y < 0)
      body[i].segement.y = GetScreenHeight() - 40;
  }
  return body;
}

Vector2 renderFood(int width, int height)
{
  float x = rand() % (width - 30);
  float y = rand() % (height - 30);

  // std::cout << "x: " << x << "\ny: " << y << std::endl;
  return {x, y};
}

snake handleInput(key_t key, snake head)
{
  if (key == KEY_UP && head.speed.y != 1)
  {
    head.speed.y = -1;
    head.speed.x = 0;
  }
  if (key == KEY_DOWN && head.speed.y != -1)
  {
    head.speed.y = 1;
    head.speed.x = 0;
  }
  if (key == KEY_LEFT && head.speed.x != 1)
  {
    head.speed.x = -1;
    head.speed.y = 0;
  }
  if (key == KEY_RIGHT && head.speed.x != -1)
  {
    head.speed.x = 1;
    head.speed.y = 0;
  }

  return head;
}

snake add_segment(snake last)
{
  snake *tail = new snake({last.segement.x - (40 * last.speed.x), last.segement.y - (40 * last.speed.y)}, last.speed);
  return *tail;
}

bool gameOver(std::vector<snake> body)
{
  bool gameover = false;
  for (size_t i = 0; i < body.size(); i++)
  {
    for (size_t j = 0; j < body.size(); j++)
    {
      if (i == j)
        continue;
      if (gameover)
        break;
      gameover = CheckCollisionRecs(body[i].segement, body[j].segement);
    }
    if (gameover)
      break;
  }

  return gameover;
}

int main()
{
  int winw = 800, winh = 600;
  InitWindow(winw, winh, "Snake");
  SetExitKey(KEY_Q);
  SetTargetFPS(FPS);

  srand(time(0));

  std::vector<snake> body;
  snake *segment = new snake({100, 100});
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

    BeginDrawing();
    ClearBackground(BLACK);

    if (eaten)
    {
      eaten = false;
      foodPos = renderFood(winw, winh);
      food = {foodPos.x, foodPos.y, 30, 30};
      // std::cout << "speed of last segment " << body[body.size() - 1].speed.x << " " << body[body.size() - 1].speed.y << std::endl;
      body.push_back(add_segment(body[body.size() - 1]));
    }
    DrawRectangleRec(food, RED);

    body = update(body);
    draw(body);
    if (gameOver(body))
    {
      std::cout << "GAME OVER" << std::endl;
      break;
    }

    eaten = CheckCollisionRecs(body[0].segement, food);

    body[0] = handleInput(GetKeyPressed(), body[0]);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}