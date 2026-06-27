#ifndef CHAVE_H
#define CHAVE_H
#include "raylib.h"

typedef struct Chave{

    int x;
    int y;
    int coletada;

} Chave;

extern Chave chave;

void InitChave(int chave_aparece );


void DrawChave(int chave_aparece );

void DescarregarChave();

void Verificar_Chave(float x, float y, int chave_aparece  );



#endif