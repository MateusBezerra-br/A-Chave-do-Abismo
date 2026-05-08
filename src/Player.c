#include "raylib.h"
#include "Player.h"
#include "Mapa.h"


void InitPlayer(Player *p){
    p->x = 784;
    p->y = 784;
    p->veloc = 100;
    p->raio= 5;
}

 int Colisaoparede (float x, float y, float raio){
        
        int cima = (int)(y - raio) / TILE;
        int baixo = (int)(y + raio) / TILE;
        int esquerda = (int)(x - raio) / TILE;
        int direita  = (int)(x + raio) / TILE;

        if(is_parede(cima, esquerda)) return 1;
        if(is_parede(cima, direita)) return 1;
        if(is_parede(baixo, esquerda)) return 1;
        if(is_parede(baixo, direita)) return 1;

        return 0;
 }

void UpdatePlayer(Player *p){

    float dt = GetFrameTime();
    float novo_x = p->x;
    float novo_y = p->y;

    if(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        novo_x += p->veloc * dt;
    }
    if(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        novo_x -= p->veloc * dt;
    }
    if(IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))  { 
        novo_y -= p->veloc * dt;
    }
    if(IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) { 
        novo_y += p->veloc * dt;
    }
    if(!Colisaoparede(novo_x, p->y, p->raio)){
        p->x = novo_x;
    }
    if(!Colisaoparede(p->x, novo_y, p->raio)){
        p->y = novo_y;
    }

}

void DrawPlayer(Player *p){
    DrawCircle((int)p->x, (int)p->y, p->raio, BLUE);
}