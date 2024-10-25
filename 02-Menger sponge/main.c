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

void DrawMengerBase(int offsetX, int offsetY, int offsetZ) {
  for (int x = 0; x < edge; x++) {
    for (int y = 0; y < edge; y++) {
      for (int z = 0; z < edge; z++) {
        if ((x == 1 && y == 1) || (z == 1 && (y == 1 || x == 1)))
          continue;
        else {
          Vector3 drawPos = {offsetX + (x * SIDE), offsetY + (y * SIDE),
                             offsetZ + (z * SIDE)};
          DrawCube(drawPos, SIDE, SIDE, SIDE, BLUE);
          DrawCubeWires(drawPos, SIDE, SIDE, SIDE, DARKBLUE);
        }
      }
    }
  }
}

void DrawMenger(int level, int offsetX, int offsetY, int offsetZ) {
  printf("offset for level %d\n ", level);

  if (level > 1) {
    for (int x = 0; x < edge; x++) {
      for (int y = 0; y < edge; y++) {
        for (int z = 0; z < edge; z++) {
          DrawMenger(level - 1, x * pow(3, level - 1) * SIDE,
                     y * pow(3, level - 1) * SIDE,
                     z * pow(3, level - 1) * SIDE);
        }
      }
    }
  } else {
    DrawMengerBase(offsetX, offsetY, offsetZ);
  }
}

int main(void) {
  int winw = 800;
  int winh = 600;
  int level = 2;
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
    if (IsKeyPressed(KEY_ENTER)) {
      level++;
      TraceLog(LOG_INFO, "level = %d", level);
    }

    BeginDrawing();

    BeginMode3D(camera);

    ClearBackground(BLACK);

    DrawMenger(level, pow(3, level) * SIDE, pow(3, level) * SIDE,
               pow(3, level) * SIDE);

    // DrawMengerBase();

    EndMode3D();
    DrawFPS(10, 10);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}