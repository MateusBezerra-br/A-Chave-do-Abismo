#include "raylib.h"
#include "Papeis.h"
#include "Mapa.h"
#include "Player.h"
#include <stdio.h>

int i;

Papeis papeis[4];

static Texture2D textura_papeis;

void InitPapeis()
{

    papeis[0].x = 1345.3;
    papeis[0].y = 90.6;
    papeis[1].x = 1435.3;
    papeis[1].y = 1151.3;
    papeis[2].x = 126.6;
    papeis[2].y = 1558.6;
    papeis[3].x = 78.6;
    papeis[3].y = 155.3;

    papeis[0].coletado = 1;
    papeis[1].coletado = 1;
    papeis[2].coletado = 1;
    papeis[3].coletado = 1;

    textura_papeis = LoadTexture("assets/tilesets_papeis.png");
};

void Drawpapeis()
{

    Rectangle papel = {192, 160, 16, 16};
    for (i = 0; i < 4; i++)
    {
        if (papeis[i].coletado == 1)
        {
            DrawTextureRec(textura_papeis, papel, (Vector2){papeis[i].x, papeis[i].y - 16}, WHITE);
        }
    }
}

static int colide_papel(float x, float y, float raio, float ox, float oy, float ow, float oh)
{
    Rectangle rect = {ox, oy, ow, oh};
    return CheckCollisionCircleRec((Vector2){x, y}, raio, rect);
}

void Verificar_papel(float px, float py, Sound coleta)
{
    for (i = 0; i < 4; i++)
    {
        if (papeis[i].coletado == 1)
        {
            if (colide_papel(px, py, 20, papeis[i].x, papeis[i].y - 16, 16, 16))
            {
                PlaySound(coleta);
                papeis[i].coletado = 0;
            }
        }
    }
}

void DescarregarPapel()
{

    UnloadTexture(textura_papeis);
}
