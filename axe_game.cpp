#include "raylib.h"

#define BACKGROUND_COLOR  (Color) { 128, 0, 128, 255 }
#define PLAYER_COLOR      (Color) { 189, 53, 122, 255 }
#define OBSTACLE_COLOR    (Color) { 0, 0, 0, 255 }
const int fps = 60;

int main()
{
    // WINDOW CONSTRAINTS
    int width = 1366;
    int height = 768;

    // CIRCLE CONSTRAINTS
    int centerX = width / 2;
    int centerY = height / 2;
    int radius = 25;
    int moveSpeed = 10;

    const char* title = "Axe Game";

    InitWindow(width, height, title);

    SetTargetFPS(fps);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);

        DrawCircle(centerX, centerY, radius, PLAYER_COLOR);

        if (IsKeyDown(KEY_D) && (centerX + radius) < width)
        {
            centerX += moveSpeed;
        }
        if (IsKeyDown(KEY_A) && (centerX - radius) > 0)
        {
            centerX -= moveSpeed;
        }
        if (IsKeyDown(KEY_W) && (centerY - radius) > 0)
        {
            centerY -= moveSpeed;
        }
        if (IsKeyDown(KEY_S) && (centerY + radius) < height)
        {
            centerY += moveSpeed;
        }

        EndDrawing();
    }
}