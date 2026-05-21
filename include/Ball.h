#ifndef BALL_H
#define BALL_H

#include "raylib.h"

typedef struct Ball
{
    Vector2 position;
    Vector2 speed;
    float radius;
    Color color;

} Ball;

void InitBall(Ball *ball, float x, float y, float speedX, float speedY);

void UpdateBall(Ball *ball);

void DrawBall(Ball *ball);

#endif