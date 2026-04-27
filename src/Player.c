#include "raylib.h"
#include "Player.h"

void InitPlayer(Player *p){
    p->x = 600;
    p->y = 400;
    p->veloc = 200;
    p->raio= 15;
}

void UpdatePlayer(Player *p){

    float dt = GetFrameTime();

    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        p->x += p->veloc * dt;
    }

    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        p->x -= p->veloc * dt;
    }

    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        p->y -= p->veloc * dt;
    }

    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
        p->y += p->veloc * dt;
    }
}

void DrawPlayer(Player *p){
    DrawCircle((int)p->x, (int)p->y, p->raio, BLUE);
}