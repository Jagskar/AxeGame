#include "raylib.h"
#include <iostream>

#define BACKGROUND_COLOR  (Color) { 128, 0, 128, 255 }
#define PLAYER_COLOR      (Color) { 189, 53, 122, 255 }
#define OBSTACLE_COLOR    (Color) { 0, 0, 0, 255 }

// FRAME RATE CONSTRAINT
const int fps = 60;

// OBSTACLE CONSTRAINTS
const int obstacleHeight = 50;
const int obstacleWidth = 50;

// WINDOW CONSTRAINTS
const int windowWidth = 1366;
const int windowHeight = 768;

int calculateMoveSpeed(int posY, int moveSpeed)
{
    if ((posY <= 0 && moveSpeed < 0) || (posY + obstacleHeight >= windowHeight && moveSpeed > 0))
    {
        return moveSpeed *= -1;
    }
    return moveSpeed;
}

int main()
{
    // CIRCLE CONSTRAINTS
    int centerX = windowWidth / 2;
    int centerY = windowHeight / 2;
    int radius = 25;
    int moveSpeed = 10;

    // OBSTACLE SETUP
    int obstacle1X = (windowWidth * 0.25) + obstacleWidth;
    int obstacle1Y = 0;
    int obstacle1MoveSpeed = 5;
    
    int obstacle2X = (windowWidth * 0.75) - obstacleWidth;
    int obstacle2Y = windowHeight - obstacleHeight;
    int obstacle2MoveSpeed = 5;

    const char* title = "Axe Game";

    InitWindow(windowWidth, windowHeight, title);

    SetTargetFPS(fps);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);

        DrawRectangle(obstacle1X, obstacle1Y, obstacleWidth, obstacleHeight, OBSTACLE_COLOR);
        DrawRectangle(obstacle2X, obstacle2Y, obstacleWidth, obstacleHeight, OBSTACLE_COLOR);

        obstacle1Y += obstacle1MoveSpeed;
        obstacle2Y += obstacle2MoveSpeed;

        obstacle1MoveSpeed = calculateMoveSpeed(obstacle1Y, obstacle1MoveSpeed);
        obstacle2MoveSpeed = calculateMoveSpeed(obstacle2Y, obstacle2MoveSpeed);

        DrawCircle(centerX, centerY, radius, PLAYER_COLOR);

        if (IsKeyDown(KEY_D) && (centerX + radius) < windowWidth)
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
        if (IsKeyDown(KEY_S) && (centerY + radius) < windowHeight)
        {
            centerY += moveSpeed;
        }

        EndDrawing();
    }
}