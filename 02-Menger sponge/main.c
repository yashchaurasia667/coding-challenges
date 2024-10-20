#include <math.h>
#include <raylib.h>
#include <stdio.h>

#define FPS 60
#define SIDE 2.0f
#define edge 3

struct cube {
  float x;
  float y;
  float z;
};

typedef struct cube Cube;

void DrawMengerBase(int offset) {
  for (int z = 0; z < edge; z++) {
    for (int y = 0; y < edge; y++) {
      for (int x = 0; x < edge; x++) {
        if ((x == 1 && y == 1) || (z == 1 && (y == 1 || x == 1)))
          continue;
        else {
          Vector3 drawPos = {offset + (z * SIDE), offset + (y * SIDE),
                             offset + (x * SIDE)};
          DrawCube(drawPos, SIDE, SIDE, SIDE, BLUE);
          DrawCubeWires(drawPos, SIDE, SIDE, SIDE, DARKBLUE);
        }
      }
    }
  }
}

void DrawMenger(int level) {
  int blocks = pow(3, level - 1);
  int offset = blocks * SIDE;

  if (level > 0) {
    for (int x = 0; x < level; x++) {
      for (int y = 0; y < level; y++) {
        for (int z = 0; z < level; z++) {
          DrawMenger(level - 1);
        }
      }
    }
    return;
  }
  DrawMengerBase(offset);
}

int main(void) {
  int winw = 800;
  int winh = 600;
  // Cube cube = {0.0f, 0.0f, 0.0f};

  InitWindow(winw, winh, "Menger cube");
  SetExitKey(KEY_Q);
  SetTargetFPS(60);

  Camera3D camera = {0};
  camera.position = (Vector3){10.0f, 10.0f, 10.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  // Vector3 cubePos = {cube.x, cube.y, cube.z};

  while (!WindowShouldClose()) {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_W) ||
        IsKeyDown(KEY_S) || IsKeyDown(KEY_A) || IsKeyDown(KEY_D) ||
        IsKeyDown(KEY_Q) || IsKeyDown(KEY_E))
      UpdateCamera(&camera, CAMERA_FREE);

    if (IsKeyPressed('Z')) camera.target = (Vector3){0.0f, 0.0f, 0.0f};

    BeginDrawing();

    BeginMode3D(camera);

    ClearBackground(BLACK);

    DrawMenger(2);

    // DrawMengerBase();

    EndMode3D();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}