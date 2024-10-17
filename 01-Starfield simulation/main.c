#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <time.h>

#define WINW 1280
#define WINH 720
#define FPS 60
#define STARS 300
#define RADIUS 6

struct star
{
  int x, y, z, r;
};

typedef struct star Star;

void initStars(Star *st[])
{
  for (int i = 0; i < STARS; i++)
  {
    st[i] = malloc(sizeof(Star));
    if (st[i] == NULL)
    {
      printf("Failed to allocate memory...\n");
      exit(1);
    }
    st[i]->x = rand() % WINW;
    st[i]->y = rand() % WINH;
    st[i]->z = rand() % WINW;
    st[i]->r = RADIUS;
  }
}

void DrawStar(int x, int y, int r)
{
  DrawCircle(x, y, r, WHITE);
}

void update(Star *s)
{
  
}

int main()
{
  srand(time(0));
  Star *stars[STARS];
  initStars(stars);

  // for (int i = 0; i < STARS; i++)
  // {
  //   printf("x= %d\n", stars[i]->x);
  // }

  InitWindow(WINW, WINH, "Starfield simulation");
  SetTargetFPS(FPS);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);
    for (int i = 0; i < STARS; i++)
      DrawStar(stars[i]->x, stars[i]->y, RADIUS);
    EndDrawing();
  }
  return 0;
}