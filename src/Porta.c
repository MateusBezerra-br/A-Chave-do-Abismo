#include "porta.h"
#include "Mapa.h"
#include "raylib.h"

Porta porta= {0, 0};

static Texture2D textura_porta;

void InitPorta(){

    porta.x = 772;
    porta.y = 757;
    
    textura_porta = LoadTexture("assets/tilesets_dungeon.png");
}

float porta_x= 769, porta_y= 748;

 void DrawPorta() {
    Rectangle origem_cima  = {160, 96,  16+3, 16};
    Rectangle origem_baixo = {160, 112, 16+3, 16};
    DrawTextureRec(textura_porta, origem_cima,  (Vector2){porta_x, porta_y - 16}, WHITE);
    DrawTextureRec(textura_porta, origem_baixo, (Vector2){porta_x, porta_y},      WHITE);

}



   void verificar_porta(float px, float py, int tem_chave, int *venceu) {
    float dx = px - porta.x;
    float dy = py - porta.y;
    float dist = dx*dx + dy*dy;

    if(dist < 200 ) {
        if(tem_chave) *venceu = 1;
    }
}

void DescarregarPorta(){

    UnloadTexture(textura_porta);
}