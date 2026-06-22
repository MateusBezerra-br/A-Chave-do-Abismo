#include "raylib.h"
#include "Bau.h"
#include "Player.h"

extern Font fonte_texto;
static int acertou= 0;
static float tempo_acerto = 0;
static int mostrando_charada = 0;
static int opcao_selecionada = 0;
static Texture2D textura_bau;

Bau bau = {796.0 , 743.666, 0};

 void DescarregarBau( ){
        UnloadTexture(textura_bau);
 }



int esta_na_charada(){
    return mostrando_charada;
}


void InitBau(){

    bau.chave_entregue = 0;

    textura_bau = LoadTexture("assets/Bau.png");

};

void DrawBau(){

   
     DrawTextureEx(
            textura_bau,
            (Vector2){bau.x ,bau.y },
            0.0f,   
            0.17f,   
            WHITE
        );
    
   


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
   
    DrawRectangle(0, 0, 1300, 1000, (Color){50, 50, 100, 220});

    
   
    DrawTextEx(fonte_texto,"Não tenho corpo, mas posso lhe mostrar mil rostos.", (Vector2){40, 50}, 22,1, WHITE);
    DrawTextEx(fonte_texto,"Não tenho mãos, mas construo cidades, oceanos e mundos inteiros.", (Vector2){40, 85}, 22, 1, WHITE);
    DrawTextEx(fonte_texto,"Não tenho voz, mas sussurro em todas as línguas.", (Vector2){40, 120}, 22, 1,  WHITE);
    DrawTextEx(fonte_texto,"Cientistas me estudam noite após noite, mas não conseguem me entender.", (Vector2){40, 155}, 22, 1, WHITE);

    DrawTextEx(fonte_texto,"Poetas me perseguem em suas obras.", (Vector2){40, 190}, 22, 1, WHITE);
    DrawTextEx(fonte_texto,"Pintores tentam reproduzir minhas formas sem nunca terem me visto.", (Vector2){40, 225}, 22, 1, WHITE);
    DrawTextEx(fonte_texto,"Sou o lugar que você conhece intimamente, embora nunca o encontre em um mapa.", (Vector2){40, 260}, 22, 1, WHITE);


    DrawTextEx(fonte_texto,"Já fui seu refúgio, seu desejo mais profundo e o palco de seus maiores medos.", (Vector2){40, 295}, 22, 1, WHITE);
    DrawTextEx(fonte_texto,"Às vezes lhe entrego respostas.", (Vector2){40, 330}, 22, 1, WHITE);
    DrawTextEx(fonte_texto,"Às vezes lhe mostro monstros.", (Vector2){40, 365}, 22, 1, WHITE);
    DrawTextEx(fonte_texto,"Quase sempre desapareço antes que o sol termine de nascer.", (Vector2){40, 400}, 22, 1, WHITE);
    DrawTextEx(fonte_texto,"Existo apenas quando você abandona a necessidade de me encontrar.", (Vector2){40, 435}, 22, 1, WHITE);
    DrawTextEx(fonte_texto,"Morro no instante em que tenta me segurar.", (Vector2){40, 470}, 22, 1, WHITE);

    DrawTextEx(fonte_texto,"Diga-me, O que sou eu ?", (Vector2){40, 505}, 20, 1, WHITE);

    
    const char *opcoes[4] = {
        "1. O sonho",
        "2. Passagem do tempo",
        "3. Memoria humana",
        "4. A imaginação"
    };

    DrawTextEx(fonte_texto,"Escolha a resposta :", (Vector2){100, 550}, 20, 1, PURPLE);

    for(int i = 0; i < 4; i++) {
        Color cor = (i == opcao_selecionada) ? YELLOW : WHITE;
        DrawTextEx(fonte_texto,opcoes[i], (Vector2){100, 580 + i * 40}, 21, 1, cor);
    }

    DrawTextEx(fonte_texto,"[ 1 ] [ 2 ] [ 3 ] [ 4 ] Opções   [ ESC ] Voltar  [ ENTER ] Confirmar", (Vector2){100, 760}, 19, 1, PURPLE);

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
            tempo_acerto= 2.4f;
        } else if(opcao_selecionada != 0 ) {
            
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
        DrawTextEx(fonte_texto,"VOCE ACERTOU! Pegue a chave!", (Vector2){320, 870}, 24, 1, WHITE);
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



