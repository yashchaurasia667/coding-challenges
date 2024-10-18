#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WINW 1280
#define WINH 720
#define FPS 60
#define STARS 300
#define RADIUS 1
#define SPEED 1.2

struct star
{
  int x;
  int y;
  float z;
  float r;
};

typedef struct star Star;

void init(Star *st)
{
  st->x = (rand() % (int)(WINW)) - (int)(WINW / 2);
  st->y = (rand() % (int)(WINH)) - (int)(WINH / 2);
  st->z = SPEED;
  st->r = RADIUS;
}

void DrawStar(int x, int y, int r)
{
  DrawCircle(x + (int)(WINW / 2), y + (int)(WINH / 2), r, WHITE);
  // printf("%d\t", x);
}

void update(Star *s)
{
  s->x = s->x * s->z;
  s->y = s->y * s->z;
  if (s->r < 4)
    s->r *= 2;
  if (s->x >= WINW || s->x <= -(int)(WINW / 2) || s->x == 0 || s->y == 0 || s->y >= WINH || s->y <= -(int)(WINH / 2))
    init(s);
}

int main()
{
  srand(time(0));
  Star *stars[STARS];

  for (int i = 0; i < STARS; i++)
  {
    stars[i] = (Star *)malloc(sizeof(Star));
    init(stars[i]);
  }

  InitWindow(WINW, WINH, "Starfield simulation");
  SetTargetFPS(FPS);

  double startTime = GetTime();
  const double updateInterval = 0.2;

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);
    for (int i = 0; i < STARS; i++)
    {
      DrawStar(stars[i]->x, stars[i]->y, stars[i]->r);
      double currentTime = GetTime();
      if ((currentTime - startTime) >= updateInterval)
        update(stars[i]);
    }
    usleep(500);

    EndDrawing();
  }
  CloseWindow();
  return 0;
}