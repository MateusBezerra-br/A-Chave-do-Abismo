#ifndef PAPEIS_H
#define PAPEIS_H
#include "raylib.h"

typedef struct {

    float x;
    float y;

    int coletado;

} Papeis;

extern Papeis papeis[4];

void InitPapeis();

void Drawpapeis();

void Verificar_papel(float px, float py);


void DescarregarPapel();







#endif