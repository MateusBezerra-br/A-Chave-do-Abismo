#include "porta.h"
#include "Mapa.h"
#include "raylib.h"
#include <stdio.h>
Porta porta= {0, 0};

static Texture2D textura_porta;

void InitPorta(){

    porta.x = 769;
    porta.y = 748;
    
    textura_porta = LoadTexture("assets/tilesets_dungeon.png");
}


 void DrawPorta() {
    Rectangle origem_cima  = {160, 96,  16, 16};
    Rectangle origem_baixo = {160, 112, 16, 16};
    DrawTextureRec(textura_porta, origem_cima,  (Vector2){porta.x, porta.y - 16}, WHITE);
    DrawTextureRec(textura_porta, origem_baixo, (Vector2){porta.x, porta.y},      WHITE);

}



   void verificar_porta(float px, float py, int tem_chave, int *venceu) {
    float dx = px - porta.x;
    float dy = py - porta.y;
    float dist = dx*dx + dy*dy;

    if(dist < 20 * 20) {
        if(tem_chave) *venceu = 1;
    }
}

void DescarregarPorta(){

    UnloadTexture(textura_porta);
}