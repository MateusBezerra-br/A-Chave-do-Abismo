#include "raylib.h"
#include "Bau.h"


static int acertou= 0;
static float tempo_acerto = 0;
static int mostrando_charada = 0;
static int opcao_selecionada = 0;
static Texture2D textura_bau;

Bau bau = {800.0 , 747.666, 0};

 void DescarregarBau( ){
        UnloadTexture(textura_bau);
 }



int esta_na_charada(){
    return mostrando_charada;
}


void InitBau(){

    bau.chave_entregue = 0;

    textura_bau = LoadTexture("assets/tilesets_bau.png");

};

void DrawBau(){

    Rectangle origem = {32, 0,  16, 16};
    Vector2 pos = {bau.x, bau.y};
    BeginBlendMode(BLEND_ALPHA);
    DrawTextureRec(textura_bau, origem, pos, (Color){255,255,255,255});
    EndBlendMode();


};


int Proximo_ao_Bau(float px, float py) {
   
    Rectangle area = {
        bau.x - 16,  
        bau.y - 16,  
        40,          
        40           
    };

    return CheckCollisionPointRec((Vector2){px, py}, area);
};




void desenhar_tela_charada(int *vidas, int *tem_chave) {
   
    DrawRectangle(0, 0, 1300, 1000, (Color){0, 0, 0, 220});

    
    DrawText("Existo desde antes da linguagem mas so fui nomeada depois dela.", 100, 180, 16, WHITE);
    DrawText("Nao tenho forma mas assumo todas as formas.", 100, 210, 16, WHITE);
    DrawText("Nao tenho voz mas falo em todas as linguas.", 100, 240, 16, WHITE);
    DrawText("Cientistas me estudam sem me entender.", 100, 270, 16, WHITE);
    DrawText("Artistas me retratam sem me ver.", 100, 300, 16, WHITE);
    DrawText("Sou o lugar que voce conhece mas nunca encontrara no mapa.", 100, 330, 16, WHITE);
    DrawText("Fui seu refugio e seu pesadelo sem jamais pedir permissao.", 100, 360, 16, WHITE);
    DrawText("Existo apenas quando voce para de procurar.", 100, 390, 16, WHITE);
    DrawText("O QUE SOU?", 100, 430, 20, PURPLE);

    
    const char *opcoes[4] = {
        "1. Mundo dos sonhos",
        "2. Passagem do tempo",
        "3. Memoria humana",
        "4. Paz de espirito"
    };

    DrawText("Escolha a resposta:", 100, 500, 20, WHITE);

    for(int i = 0; i < 4; i++) {
        Color cor = (i == opcao_selecionada) ? GREEN : WHITE;
        DrawText(opcoes[i], 100, 540 + i * 40, 20, cor);
    }

    DrawText("[1][2][3][4] Escolher   [ESC] Voltar", 100, 720, 16, DARKGRAY);

    if(IsKeyPressed(KEY_ONE))   opcao_selecionada = 0;
    if(IsKeyPressed(KEY_TWO))   opcao_selecionada = 1;
    if(IsKeyPressed(KEY_THREE)) opcao_selecionada = 2;
    if(IsKeyPressed(KEY_FOUR))  opcao_selecionada = 3;

    if(IsKeyPressed(KEY_ENTER)) {
        if(opcao_selecionada == 0) {
             
            *tem_chave = 1;
            bau.chave_entregue = 1;
            mostrando_charada = 0;
            acertou= 1;
            tempo_acerto= 3.0f;
        } else {
            
            *vidas -= 1;
            mostrando_charada = 0;
        }
    }

    if(IsKeyPressed(KEY_ESCAPE))
        mostrando_charada = 0;
}


 void Interacao_Bau(float px, float py, int fragmentos_coletados, int *vidas, int *tem_chave ){
              if(acertou) {
        tempo_acerto -= GetFrameTime();
        DrawRectangle(300, 850, 700, 80, (Color){0, 0, 0, 220});
        DrawText("VOCE ACERTOU! Pegue a chave!", 320, 870, 24, GREEN);
        if(tempo_acerto <= 0) acertou = 0;
    }
    
    if(bau.chave_entregue) return;
   
        if(Proximo_ao_Bau(px, py)){
            if(fragmentos_coletados < 4){

                return;
            }

            if(IsKeyPressed(KEY_E)){
                    mostrando_charada = 1;
            }

        }


            if(mostrando_charada){
                desenhar_tela_charada(vidas, tem_chave);
            }

     
};



