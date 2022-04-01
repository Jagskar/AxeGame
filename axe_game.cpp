#include "raylib.h"
#include <iostream>

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

    // OBSTACLE CONSTRAINTS
    int obstacleHeight = 50;
    int obstacleWidth = 50;

    int obstacle1X = (width * 0.25) + obstacleWidth;
    int obstacle1Y = 0;
    int obstacle1MoveSpeed = 5;
    
    int obstacle2X = (width * 0.75) - obstacleWidth;
    int obstacle2Y = height - obstacleHeight;
    int obstacle2MoveSpeed = 5;

    const char* title = "Axe Game";

    InitWindow(width, height, title);

    SetTargetFPS(fps);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);

        DrawRectangle(obstacle1X, obstacle1Y,obstacleWidth, obstacleHeight, OBSTACLE_COLOR);
        DrawRectangle(obstacle2X, obstacle2Y, obstacleWidth, obstacleHeight, OBSTACLE_COLOR);

        obstacle1Y += obstacle1MoveSpeed;
        obstacle2Y += obstacle2MoveSpeed;

        if ((obstacle1Y <= 0 && obstacle1MoveSpeed < 0) || (obstacle1Y + obstacleHeight >= height && obstacle1MoveSpeed > 0))
        {
            obstacle1MoveSpeed *= -1;
        }

        if ((obstacle2Y <= 0 && obstacle2MoveSpeed < 0) || (obstacle2Y + obstacleHeight >= height && obstacle2MoveSpeed > 0))
        {
            obstacle2MoveSpeed *= -1;
        }

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