#include <iostream>
#include <vector>
#include "snake.h"
#include <raylib.h>

#define FPS 20
#define SPEED 40
#define FOODPOINT 50

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
    if (body[i].segement.x > GetScreenWidth() - 40)
      body[i].segement.x = 0;
    else if (body[i].segement.x < 0)
      body[i].segement.x = GetScreenWidth() - 40;
    if (body[i].segement.y > GetScreenHeight() - 40)
      body[i].segement.y = 0;
    else if (body[i].segement.y < 0)
      body[i].segement.y = GetScreenHeight() - 40;
  }
  return body;
}

Rectangle renderFood(std::vector<snake> body)
{
  Rectangle food;
  bool collision = false;
  do
  {
    float x = rand() % (GetRenderWidth() - 30);
    float y = rand() % (GetRenderHeight() - 30);
    food = {x, y, 30, 30};

    for (size_t i = 0; i < body.size(); i++)
    {
      if (CheckCollisionRecs(body[i].segement, food))
      {
        collision = true;
        break;
      }
      collision = false;
    }
  } while (collision);

  // std::cout << "x: " << x << "\ny: " << y << std::endl;
  return food;
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
    for (size_t j = i + 1; j < body.size(); j++)
    {
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
  int score = 0;
  int winw = 800, winh = 600;
  InitWindow(winw, winh, "Snake");
  SetExitKey(KEY_Q);
  SetTargetFPS(FPS);

  srand(time(0));

  std::vector<snake> body;
  snake *segment = new snake({100, 100});
  body.push_back(*segment);

  Rectangle food = renderFood(body);
  bool eaten = false;
  bool gameover;

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
      score += FOODPOINT;
      eaten = false;
      food = renderFood(body);
      // std::cout << "speed of last segment " << body[body.size() - 1].speed.x << " " << body[body.size() - 1].speed.y << std::endl;
      body.push_back(add_segment(body[body.size() - 1]));
    }
    DrawRectangleRec(food, RED);

    if (!gameover)
    {
      body = update(body);
      gameover = gameOver(body);
    }
    draw(body);

    eaten = CheckCollisionRecs(body[0].segement, food);

    body[0] = handleInput(GetKeyPressed(), body[0]);

    DrawText(TextFormat("Score: %d", score), 10, 10, 40, BLUE);

    if (gameover)
      DrawText("GAME OVER", winw / 2 - 200, winh / 2 - 40, 80, RED);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}