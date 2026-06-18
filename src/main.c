#include "raylib.h"
#include "Player.h"
#include "Mapa.h"
#include "Camera.h"
#include "Bau.h"
#include "Porta.h"
#include "Papeis.h"
#include "Npcs.h"
#include <stdio.h>
#include "Ball.h"
#include "GameOver.h"

 int todos_coletados(){
     int i;
    for(i=0 ; i < 4; i++){
       
        if(papeis[i].coletado == 1){
      
      return 0;
     }

    }

    return 1;
    };

    Font fonte_texto;
    


int main(void) {

   
    InitWindow(1300, 1000, "A Chave do Abismo");
     SetExitKey(KEY_O);
    SetTargetFPS(60);
    
    
    carregar_mapa();


     Player player;
    InitPlayer(&player);
    
   
    InitBau();
    int tem_chave = 0;
   
    int venceu= 0;
    
    

    InitPorta();
    InitPapeis();
    InitNpc();

    
    fonte_texto = LoadFontEx("assets/bedstead-bold.otf",32, 0, 500);
SetTextureFilter(fonte_texto.texture, TEXTURE_FILTER_POINT);

Camera2D camera = {0};

InitCamera(&camera, &player);

Ball balls[4];

InitBall(&balls[0], 156, 1481, 200, 0); 
InitBall(&balls[1], 1540, 1160, 100, 120); 
InitBall(&balls[2], 1187, 109, -200, 0); 
InitBall(&balls[3], 131, 227, 120, 40); 



    while (!WindowShouldClose()) {

        for (int i = 0; i < 4; i++) {
            UpdateBall(&balls[i]);
        }


        AtualizarCamera(&camera, &player);

        if(!esta_na_charada())
            UpdatePlayer(&player);
           Verificar_papel(player.x, player.y);

           UpdateNpcs(player.x,player.y, &player.vidas);

        BeginDrawing();

        ClearBackground(BLACK);
        
        

        BeginMode2D(camera);

            
            camera.target = (Vector2){player.x, player.y};
            
            desenhar_mapa();
            

              for (int i = 0; i < 4; i++) {
            DrawBall(&balls[i]);



   }

            DrawPlayer(&player);
            DrawBau();
            DrawPorta();
            Drawpapeis();
            DrawNpcs();
             EndMode2D();
        




             for(int i = 0; i < 4; i++) {
    Color cor = (i < player.vidas) ? RED : DARKGRAY;
    DrawCircle(30 + i * 40, 30, 14, cor);
    }

        verificar_porta(player.x, player.y, tem_chave, &venceu);


float dx = player.x - porta.x ;
float dy = player.y - porta.y ;
if(dx*dx + dy*dy < 200 && !tem_chave) {
    DrawRectangle(50, 850, 1200, 60, (Color){0,0,0,200});
    DrawTextEx(fonte_texto,"Voce precisa da chave para abrir esta porta!", (Vector2){70, 865}, 24, 1, (Color){ 180, 106, 79, 255 });
}
     
        
if(Proximo_ao_Bau(player.x, player.y) && !todos_coletados()) {
    DrawRectangle(50, 850, 1200, 60, (Color){0,0,0,200});
    DrawTextEx(fonte_texto,"Encontre os 4 fragmentos antes de me responder!", (Vector2){70, 865}, 24, 1,  WHITE);
}


if(Proximo_ao_Bau(player.x, player.y) && todos_coletados() && !bau.chave_entregue) {
    DrawRectangle(50, 850, 1200, 60, (Color){0,0,0,200});
    DrawTextEx(fonte_texto,"[ E ] Responder a charada do bau", (Vector2){70, 865}, 24, 1,  GOLD);
}


Interacao_Bau(player.x, player.y, todos_coletados() ? 4 : 0, &player.vidas, &tem_chave);

if(venceu) {
    DrawRectangle(0, 0, 1300, 1000, (Color){0, 0, 0, 220});
    DrawTextEx(fonte_texto,"VOCE ESCAPOU!", (Vector2){400, 350}, 48, 1, GOLD);
    DrawTextEx(fonte_texto,"PARABENS !", (Vector2){500, 430}, 27, 1, WHITE);
    DrawTextEx(fonte_texto,"[ENTER] Jogar novamente", (Vector2){300, 520}, 20, 1, GRAY);

    if(IsKeyPressed(KEY_ENTER)) {
        venceu = 0;
        tem_chave = 0;
        InitBau();
        InitPlayer(&player);
    }
    
}
if(player.vidas == 0){

        GameOver( &player, &tem_chave);
        
        
        }



            DrawFPS(10, 950);
             
             
            
            
            

           

        EndDrawing();
    }

    UnloadFont(fonte_texto);
    DescarregarNpcs();
    DescarregarPapel();
    DescarregarPorta();
    DescarregarBau();
    descarregar_mapa();
    CloseWindow();

    return 0;
}




