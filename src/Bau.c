#include "raylib.h"
#include "Bau.h"
#include "Player.h"

extern Font fonte_texto;
static int acertou= 0;
static float tempo_acerto = 0;
static int mostrando_charada = 0;
static int opcao_selecionada = 0;
static Texture2D textura_bau;

Bau bau = {800.0 , 743.666, 0};

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
   
    DrawRectangle(0, 0, 1500, 1000, (Color){ 0, 0, 0, 180 });

    
   
    DrawTextEx(fonte_texto,"NÃO TENHO CORPO, MAS POSSO LHE MOSTRAR MIL ROSTOS.", (Vector2){80, 50}, 22,1, WHITE);
    DrawTextEx(fonte_texto,"NÃO TENHO MÃOS, MAS CONSTRUO CIDADES, OCEANOS E MUNDOS INTEIROS.", (Vector2){80, 85}, 22, 1, WHITE);
    DrawTextEx(fonte_texto,"NÃO TENHO VOZ, MAS SUSSURRO EM TODAS AS LÍNGUAS.", (Vector2){80, 120}, 22, 1,  WHITE);
    DrawTextEx(fonte_texto,"CIENTISTAS ME ESTUDAM NOITE APÓS NOITE, MAS NÃO CONSEGUEM ME ENTENDER.", (Vector2){80, 155}, 22, 1, WHITE);

    DrawTextEx(fonte_texto,"POETAS ME PERSEGUEM EM SUAS OBRAS.", (Vector2){80, 190}, 22, 1, WHITE);
    DrawTextEx(fonte_texto,"PINTORES TENTAM REPRODUZIR MINHAS FORMAS SEM NUNCA TEREM ME VISTO.", (Vector2){80, 225}, 22, 1, WHITE);
    DrawTextEx(fonte_texto,"SOU O LUGAR QUE VOCÊ CONHECE INTIMAMENTE, EMBORA NUNCA O ENCONTRE EM UM MAPA.", (Vector2){80, 260}, 22, 1, WHITE);


    DrawTextEx(fonte_texto,"JÁ FUI SEU REFÚGIO, SEU DESEJO MAIS PROFUNDO E O PALCO DE SEUS MAIORES MEDOS.", (Vector2){80, 295}, 22, 1, WHITE);
    DrawTextEx(fonte_texto,"ÀS VEZES LHE ENTREGO RESPOSTAS.", (Vector2){80, 330}, 22, 1, WHITE);
    DrawTextEx(fonte_texto,"ÀS VEZES LHE MOSTRO MONSTROS.", (Vector2){80, 365}, 22, 1, WHITE);
    DrawTextEx(fonte_texto,"QUASE SEMPRE DESAPAREÇO ANTES QUE O SOL TERMINE DE NASCER.", (Vector2){80, 400}, 22, 1, WHITE);
    DrawTextEx(fonte_texto,"EXISTO APENAS QUANDO VOCÊ ABANDONA A NECESSIDADE DE ME ENCONTRAR.", (Vector2){80, 435}, 22, 1, WHITE);
    DrawTextEx(fonte_texto,"MORRO NO INSTANTE EM QUE TENTA ME SEGURAR.", (Vector2){80, 470}, 22, 1, WHITE);

    DrawTextEx(fonte_texto,"DIGA-ME, O QUE SOU EU ?", (Vector2){80, 505}, 20, 1, WHITE);

    
    const char *opcoes[4] = {
        "1. O sonho",
        "2. Passagem do tempo",
        "3. Memoria humana",
        "4. A imaginação"
    };

    DrawTextEx(fonte_texto,"ESCOLHA A RESPOSTA :", (Vector2){140, 550}, 20, 1, PURPLE);

    for(int i = 0; i < 4; i++) {
        Color cor = (i == opcao_selecionada) ? YELLOW : WHITE;
        DrawTextEx(fonte_texto,opcoes[i], (Vector2){140, 580 + i * 40}, 21, 1, cor);
    }

    DrawTextEx(fonte_texto,"[ 1 ] [ 2 ] [ 3 ] [ 4 ] OPÇÕES   [ ESC ] VOLTAR  [ ENTER ] CONFIRMAR", (Vector2){100, 760}, 19, 1, PURPLE);

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



