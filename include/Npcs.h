#ifndef NPCS_H
#define NPCS_H
#include "raylib.h"
typedef struct {

    float x;
    float y;

    float spawnX;
    float spawnY;

    float veloc;

    int direcao;

    int estado;

    int visao;

    float tempoRespawn;

    float distancia;


} Npc;

extern Npc npcs[23];

#define PATRULHANDO 0
#define PERSEGUINDO 1
#define RESPAWN 3

void InitNpc();
void UpdateNpcs(float playerX, float playerY, int *vidas, Sound dano);
void DrawNpcs();
void DescarregarNpcs();




#endif