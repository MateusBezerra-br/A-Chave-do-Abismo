#include "Ball.h"

void InitBall(Ball *ball, float x, float y, float speedX, float speedY)
{
    ball->position = (Vector2){x, y};

    ball->speed = (Vector2){speedX, speedY};

    ball->radius = 4.0f;

    ball->color = RED;
}

void UpdateBall(Ball *ball)
{
    ball->position.x += ball->speed.x;

    ball->position.y += ball->speed.y;
}

void DrawBall(Ball *ball)
{
    DrawCircleV(ball->position, ball->radius, ball->color);
}