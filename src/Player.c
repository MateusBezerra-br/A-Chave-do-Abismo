#include "raylib.h"
#include "Player.h"
#include "Mapa.h"
#include "Bau.h"
#include "Porta.h"
#include <stdio.h>
#include "Npcs.h"

static Texture2D textura_Player;

void InitPlayer(Player *p)
{
    p->x = 799;
    p->y = 810;
    p->veloc = 100;
    p->raio = 5;
    p->vidas = 4;

    textura_Player = LoadTexture("assets/Player.png");
}

int Colisaoparede(float x, float y, float raio)
{

    int cima = (int)(y - raio) / TILE;
    int baixo = (int)(y + raio) / TILE;
    int esquerda = (int)(x - raio) / TILE;
    int direita = (int)(x + raio) / TILE;

    if (is_parede(cima, esquerda))
    {
        return 1;
    }
    if (is_parede(cima, direita))
    {
        return 1;
    }
    if (is_parede(baixo, esquerda))
    {
        return 1;
    }
    if (is_parede(baixo, direita))
    {
        return 1;
    }

    return 0;
}

static int colide_objeto(float x, float y, float raio, float ox, float oy, float ow, float oh)
{
    Rectangle rect = {ox, oy, ow, oh};
    return CheckCollisionCircleRec((Vector2){x, y}, raio, rect);
}

void UpdatePlayer(Player *p)
{

    float dt = GetFrameTime();
    float novo_x = p->x;
    float novo_y = p->y;
    float static antigo_x;
    float static antigo_y;
    float barreira_x = 769, barreira_y = 740; // barreira da porta

    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
    {
        novo_x += p->veloc * dt;
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
    {
        novo_x -= p->veloc * dt;
    }
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
    {
        novo_y -= p->veloc * dt;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
    {
        novo_y += p->veloc * dt;
    }

    if (!Colisaoparede(novo_x, p->y, p->raio))
    {
        p->x = novo_x;
    }
    if (!Colisaoparede(p->x, novo_y, p->raio))
    {
        p->y = novo_y;
    }

    if (colide_objeto(p->x - 5, p->y, p->raio, bau.x, bau.y + 4, 16, 11))
    {

        p->x -= (novo_x - antigo_x);
        p->y -= (novo_y - antigo_y);
    }
    if (colide_objeto(p->x, p->y, p->raio, porta.x, porta.y, 12, 6))
    {
        p->x -= (novo_x - antigo_x);
        p->y -= (novo_y - antigo_y);
    }
    if (colide_objeto(p->x, p->y, p->raio, barreira_x, barreira_y, 12, 16))
    {

        p->x -= (novo_x - antigo_x);
        p->y -= (novo_y - antigo_y);
    }
    else
    {
        antigo_x = p->x;
        antigo_y = p->y;
    }
}

void DrawPlayer(Player *p)
{

    DrawTextureEx(
        textura_Player,
        (Vector2){p->x - 8, p->y - 8},
        0.0f,
        0.012f,
        WHITE);
}