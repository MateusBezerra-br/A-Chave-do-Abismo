#ifndef BALL_H
#define BALL_H

#include "raylib.h"
#include "Player.h"

typedef struct Ball
{
    Vector2 position;
    Vector2 speed;
    float radius, distancia, checkX, checkY;
    Color color;
    
} Ball;

void InitBall(Ball *ball, float x, float y, float speedX, float speedY);

void UpdateBall(Ball *ball, int *vidas,float PlayerX, float PlayerY, Player *player, Sound dano);

void DrawBall(Ball *ball);

#endif