#ifndef PORTA_H
#define PORTA_H

#include "raylib.h"

typedef struct {
    float x;
    float y;
} Porta;

extern Porta porta;

void InitPorta();
void DrawPorta();
void verificar_porta(float px, float py, int tem_chave, int *venceu);
void DescarregarPorta();

#endif