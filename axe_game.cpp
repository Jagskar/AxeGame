#include "raylib.h"

#define BACKGROUND_COLOR  (Color) { 128, 0, 128, 255 }
#define CIRCLE_COLOR      (Color) { 189, 53, 122, 255 }

int main()
{
    // WINDOW CONSTRAINTS
    int width = 1366;
    int height = 768;

    // CIRCLE CONSTRAINTS
    int centerX = width / 2;
    int centerY = height / 2;
    int radius = 25;

    const char* title = "Axe Game";

    InitWindow(width, height, title);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);
        DrawCircle(centerX, centerY, radius, CIRCLE_COLOR);
        EndDrawing();
    }
}