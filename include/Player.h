#ifndef PLAYER_H
#define PLAYER_H

#include "Bau.h"
#include "Porta.h"

typedef struct {

    float x;
    float y;
    
    int veloc;
    
    int raio;

    int vidas;
    
} Player;

void InitPlayer(Player *p);

void UpdatePlayer(Player *p);

void DrawPlayer(Player *p);

int Colisaoparede(float x, float y, float raio);


#endif  