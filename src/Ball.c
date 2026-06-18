#include "Ball.h"
#include "Ball.h"
#include "Player.h"
#include <math.h>




void InitBall(Ball *ball, float x, float y, float speedX, float speedY)
{
    ball->position = (Vector2){x, y};

    ball->speed = (Vector2){speedX, speedY};

    ball->radius = 4.0f;

    ball->color = RED;

    
}

void UpdateBall(Ball *ball,int *vidas, float PlayerX, float PlayerY)
{
    

    float dt = GetFrameTime();

    float novo_x = ball->position.x + ball->speed.x * dt;
    float novo_y = ball->position.y + ball->speed.y * dt;

      
        
    float dx = ball->position.x - PlayerX;
    float dy = ball->position.y - PlayerY;

    float distancia = sqrt(dx*dx + dy*dy);

    if(distancia <= ball->radius + 10)
    {
        (*vidas)--;
    }

    

    if (ball->position.x > 1600)
{
    ball->speed.x = -fabs(ball->speed.x);
}

if (ball->position.y > 1350)
{
    ball->speed.y = -fabs(ball->speed.y);
}


    
    

    if(!Colisaoparede(novo_x, ball->position.y, ball->radius))
    {
        ball->position.x = novo_x;
    }
    else
    {
        ball->speed.x *= -1;
    }

    if(!Colisaoparede(ball->position.x, novo_y, ball->radius))
    {
        ball->position.y = novo_y;
    }
    else
    {
        ball->speed.y *= -1;
    }
}

void DrawBall(Ball *ball)
{
    DrawCircleV(ball->position, ball->radius, ball->color);
}