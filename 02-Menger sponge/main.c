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

void DrawMengerBase(int Ox, int Oy, int Oz) {
  for (int x = 0; x < edge; x++) {
    for (int y = 0; y < edge; y++) {
      for (int z = 0; z < edge; z++) {
        if ((x == 1 && y == 1) || (z == 1 && (y == 1 || x == 1)))
          continue;
        else {
          Vector3 pos =
              (Vector3){Ox + (x * SIDE), Oy + (y * SIDE), Oz + (z * SIDE)};
          DrawCube(pos, SIDE, SIDE, SIDE, BLUE);
          DrawCubeWires(pos, SIDE, SIDE, SIDE, BLACK);
        }
      }
    }
  }
}

void DrawMenger(int level, int Ox, int Oy, int Oz) {
  int offset = pow(3, level - 1) * SIDE;
  int midHole = pow(3, level - 1);
  if (level > 1) {
    for (int x = 0; x < edge; x++) {
      for (int y = 0; y < edge; y++) {
        for (int z = 0; z < edge; z++) {
          if ((x == 1 && y == 1) || (z == 1 && (y == 1 || x == 1)))
            continue;
          else
            DrawMenger(level - 1, Ox + x * offset, Oy + y * offset,
                       Oz + z * offset);
        }
      }
    }
  } else {
    DrawMengerBase(Ox, Oy, Oz);
  }
}

int main(void) {
  int winw = 800;
  int winh = 600;
  int level = 1;
  int offset = pow(3, level) * SIDE;

  InitWindow(winw, winh, "Menger cube");
  SetExitKey(KEY_Q);
  SetTargetFPS(60);

  Camera3D camera = {0};
  camera.position = (Vector3){2 * offset, 2 * offset, 2 * offset};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 0.1f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  while (!WindowShouldClose()) {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_W) ||
        IsKeyDown(KEY_S) || IsKeyDown(KEY_A) || IsKeyDown(KEY_D) ||
        IsKeyDown(KEY_Q) || IsKeyDown(KEY_E))
      UpdateCamera(&camera, CAMERA_FREE);

    if (IsKeyPressed('Z')) camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    if (IsKeyPressed(KEY_ENTER)) {
      offset = pow(3, level) * SIDE;
      camera.position = (Vector3){2 * offset, 2 * offset, 2 * offset};
      level++;
      TraceLog(LOG_INFO, "level = %d", level);
    }

    BeginDrawing();

    BeginMode3D(camera);

    ClearBackground(BLACK);
    DrawMenger(level, 0, 0, 0);

    EndMode3D();
    DrawFPS(10, 10);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}