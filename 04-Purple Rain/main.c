#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>

#define WINW 800
#define WINH 600
#define FPS 60
#define G 1.05
#define DROPS 500
#define WIND 1.07

struct drop
{
  int x;
  int y;
  float z;
  int width;
  int height;
  float sway;
};

typedef struct drop Drop;

void init(Drop *d)
{
  d->x = (rand() % WINW);
  d->y = (rand() % WINH) - WINH;
  d->z = 10;
  d->width = (rand() % 4) + 2;
  d->height = (rand() % 30) + 10;
  d->sway = rand() % 2;
}

void Draw(Drop *rain[])
{
  for (int i = 0; i < DROPS; i++)
  {
    Vector2 startPos = {rain[i]->x, rain[i]->y};
    Vector2 endPos = {rain[i]->x + rain[i]->sway, rain[i]->y + rain[i]->height};
    DrawLineEx(startPos, endPos, rain[i]->width, PURPLE);
  }
}

void update(Drop *rain[])
{
  for (int i = 0; i < DROPS; i++)
  {
    if (rain[i]->y > WINH)
      init(rain[i]);
    rain[i]->x += rain[i]->sway;
    rain[i]->y += rain[i]->z;
    if (rain[i]->z < 30)
      rain[i]->z *= G;
    if (rain[i]->sway <= 6)
      rain[i]->sway *= WIND;
    // printf("z= %f\n", rain[i]->z);
  }
}

int main()
{
  srand(time(0));
  Drop *rain[DROPS];

  for (int i = 0; i < DROPS; i++)
  {
    rain[i] = (Drop *)malloc(sizeof(Drop));
    init(rain[i]);
  }

  InitWindow(WINW, WINH, "Purple Rain");
  SetTargetFPS(FPS);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    Draw(rain);
    update(rain);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}