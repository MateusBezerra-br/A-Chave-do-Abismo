
#ifndef MAPA_H
#define MAPA_H

#include "raylib.h"

#define LINHA 100
#define COLUNA 100
#define TILE 16

#define ID_PAREDE 305
#define ID_CHAO_CENTRO 96
#define ID_BAU 2
#define ID_PAPEIS 142
#define ID_PORTA_BAIXO 171
#define ID_PORTA_CIMA 148


extern int mapa[100][100];

void carregar_mapa();

void desenhar_mapa();

void descarregar_mapa();

int is_parede(int linha, int coluna);

int get_tile(int linha, int coluna);


#endif


