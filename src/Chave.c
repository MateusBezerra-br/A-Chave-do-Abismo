#include "Chave.h"
#include "raylib.h"
#include "Bau.h"

Chave chave;
static Texture2D textura_chave;

  
void InitChave(int chave_aparece ){
    
    chave.x = 861;
    chave.y = 80;
    chave.coletada = 0;
    
     textura_chave = LoadTexture("assets/chave.png");
}



void DrawChave(int chave_aparece ){

    if(chave_aparece && chave.coletada == 0){
    
     // 861 80
    DrawTextureEx(
            textura_chave,
            (Vector2){chave.x - 7, chave.y - 7},
            0.0f,
            0.03f,
            WHITE);;
    }
   
    
}

static int colide_chave(float x, float y, float raio, float ox, float oy, float ow, float oh)
{
    Rectangle rect = {ox, oy, ow, oh};
    return CheckCollisionCircleRec((Vector2){x, y}, raio, rect);
}

void Verificar_Chave(float px, float py, int chave_aparece )
{
 
        if( chave.coletada == 0 && chave_aparece )
        {
            if (colide_chave(px, py, 3, chave.x,chave.y, 16, 16))
            {
                chave.coletada = 1;
            }
        }
    
}

void DescarregarChave(){

    UnloadTexture(textura_chave);

};
