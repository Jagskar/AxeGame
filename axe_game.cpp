#include "raylib.h"

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
    // If the position of the object hits the top or bottom edges of the screen, reverse the direction
    if ((posY <= 0 && moveSpeed < 0) || (posY + obstacleHeight >= windowHeight && moveSpeed > 0))
    {
        return moveSpeed *= -1;
    }
    return moveSpeed;
}

int main()
{
    // CIRCLE CONSTRAINTS
    int radius = 25;
    int moveSpeed = 10;
    int centerX = radius;
    int centerY = windowHeight / 2;

    // CIRCLE EDGES
    int circleUpperEdgeY = centerY - radius;
    int circleLowerEdgeY = centerY + radius;
    int circleRightEdgeX = centerX + radius;
    int circleLeftEdgeX = centerX - radius;

    // OBSTACLE SETUP
    int obstacle1X = (windowWidth * 0.25) + obstacleWidth;
    int obstacle1Y = 0;
    int obstacle1MoveSpeed = 5;
    
    int obstacle2X = (windowWidth * 0.75) - obstacleWidth;
    int obstacle2Y = windowHeight - obstacleHeight;
    int obstacle2MoveSpeed = 5;

    // OBSTACLE EDGES
    int obstacle1UpperEdgeY = obstacle1Y;
    int obstacle1LowerEdgeY = obstacle1Y + obstacleHeight;
    int obstacle1LeftEdgeX = obstacle1X;
    int obstacle1RightEdgeX = obstacle1X + obstacleWidth;

    int obstacle2LeftEdgeX = obstacle2X;
    int obstacle2RightEdgeX = obstacle2X + obstacleWidth;
    int obstacle2UpperEdgeY = obstacle2Y;
    int obstacle2LowerEdgeY = obstacle2Y + obstacleHeight;

    bool collisionWithObstacle1 = (obstacle1LowerEdgeY >= circleUpperEdgeY) &&
                                 (obstacle1UpperEdgeY <= circleLowerEdgeY) &&
                                 (obstacle1LeftEdgeX <= circleRightEdgeX) &&
                                 (obstacle1RightEdgeX >= circleLeftEdgeX);

    bool collisionWithObstacle2 = (obstacle2LowerEdgeY >= circleUpperEdgeY) &&
                                  (obstacle2UpperEdgeY <= circleLowerEdgeY) &&
                                  (obstacle2LeftEdgeX <= circleRightEdgeX) &&
                                  (obstacle2RightEdgeX >= circleLeftEdgeX);

    const char* title = "Axe Game";

    InitWindow(windowWidth, windowHeight, title);

    SetTargetFPS(fps);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);
        if (collisionWithObstacle1 || collisionWithObstacle2)
        {
            DrawText("Game Over!", (windowWidth / 2) - 80, windowHeight / 2, 40, RED);
        }
        else
        {
            // UPDATE PLAYER POSITION AT EACH FRAME
            circleLeftEdgeX = centerX - radius;
            circleRightEdgeX = centerX + radius;
            circleUpperEdgeY = centerY - radius;
            circleLowerEdgeY = centerY + radius;

            // UPDATE FIRST OBSTACLE POSITION AT EACH FRAME
            obstacle1LeftEdgeX = obstacle1X;
            obstacle1RightEdgeX = obstacle1X + obstacleWidth;
            obstacle1UpperEdgeY = obstacle1Y;
            obstacle1LowerEdgeY = obstacle1Y + obstacleHeight;

            // UPDATE SECOND OBSTACLE POSITION AT EACH FRAME
            obstacle2LeftEdgeX = obstacle2X;
            obstacle2RightEdgeX = obstacle2X + obstacleWidth;
            obstacle2UpperEdgeY = obstacle2Y;
            obstacle2LowerEdgeY = obstacle2Y + obstacleHeight;

            // UPDATE COLLISION DETECTION
            collisionWithObstacle1 = (obstacle1LowerEdgeY >= circleUpperEdgeY) &&
                                     (obstacle1UpperEdgeY <= circleLowerEdgeY) &&
                                     (obstacle1LeftEdgeX <= circleRightEdgeX) &&
                                     (obstacle1RightEdgeX >= circleLeftEdgeX);

            collisionWithObstacle2 = (obstacle2LowerEdgeY >= circleUpperEdgeY) &&
                                     (obstacle2UpperEdgeY <= circleLowerEdgeY) &&
                                     (obstacle2LeftEdgeX <= circleRightEdgeX) &&
                                     (obstacle2RightEdgeX >= circleLeftEdgeX);

            DrawCircle(centerX, centerY, radius, PLAYER_COLOR);
            DrawRectangle(obstacle1X, obstacle1Y, obstacleWidth, obstacleHeight, OBSTACLE_COLOR);
            DrawRectangle(obstacle2X, obstacle2Y, obstacleWidth, obstacleHeight, OBSTACLE_COLOR);

            obstacle1Y += obstacle1MoveSpeed;
            obstacle2Y += obstacle2MoveSpeed;

            obstacle1MoveSpeed = calculateMoveSpeed(obstacle1Y, obstacle1MoveSpeed);
            obstacle2MoveSpeed = calculateMoveSpeed(obstacle2Y, obstacle2MoveSpeed);

            if (IsKeyDown(KEY_D) && circleRightEdgeX < windowWidth)
            {
                centerX += moveSpeed;
            }
            if (IsKeyDown(KEY_A) && circleLeftEdgeX > 0)
            {
                centerX -= moveSpeed;
            }
            if (IsKeyDown(KEY_W) && circleUpperEdgeY > 0)
            {
                centerY -= moveSpeed;
            }
            if (IsKeyDown(KEY_S) && circleLowerEdgeY < windowHeight)
            {
                centerY += moveSpeed;
            }
        }

        EndDrawing();
    }
}