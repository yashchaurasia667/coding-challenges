#include "raylib.h"

#define WINW 800
#define WINH 600
#define FPS 60

typedef struct
{
  float x;
  float y;
  float z;
} Cube;

int main(void)
{
  Cube cube = {0.0f, 0.0f, 0.0f};

  InitWindow(WINW, WINH, "Menger cube");
  SetTargetFPS(60);

  // Define the camera to look into our 3d world
  Camera3D camera = {0};
  camera.position = (Vector3){0.0f, 10.0f, 10.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Vector3 cubePos = {cube.x, cube.y, cube.z};

  while (!WindowShouldClose())
  {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginMode3D(camera);

    DrawCube(cubePos, 2.0f, 2.0f, 2.0f, RED);
    DrawCubeWires(cubePos, 2.0f, 2.0f, 2.0f, MAROON);

    // DrawGrid(10, 1.0f);

    EndMode3D();

    DrawFPS(10, 10);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}