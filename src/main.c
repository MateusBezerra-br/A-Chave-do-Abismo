#include "raylib.h"
#include "Player.h"
#include "Mapa.h"
#include "Camera.h"
#include "Bau.h"
#include "Porta.h"


 int todos_coletados(){
        return 0;
    };
    
int main(void) {

   
    InitWindow(1300, 1000, "A Chave do Abismo");
     SetExitKey(KEY_NULL);
    SetTargetFPS(60);
    
    carregar_mapa();


     Player player;
    InitPlayer(&player);
    
    InitBau();
    int tem_chave = 0;
    int vidas = 3;
    int venceu= 0;

    InitPorta();

Camera2D camera = {0};

InitCamera(&camera, &player);


    while (!WindowShouldClose()) {



        AtualizarCamera(&camera, &player);

        if(!esta_na_charada())
            UpdatePlayer(&player);

        BeginDrawing();

        ClearBackground(BLACK);
        

        BeginMode2D(camera);

            
            camera.target = (Vector2){player.x, player.y};
            
            desenhar_mapa();
            
            DrawPlayer(&player);
            DrawBau();
            DrawPorta();
             EndMode2D();
        

        verificar_porta(player.x, player.y, tem_chave, &venceu);


float dx = player.x - porta.x;
float dy = player.y - porta.y;
if(dx*dx + dy*dy < 24*23 && !tem_chave) {
    DrawRectangle(50, 850, 1200, 60, (Color){0,0,0,200});
    DrawText("Voce precisa da chave para abrir esta porta!", 70, 865, 18, WHITE);
}
     
        
if(Proximo_ao_Bau(player.x, player.y) && !todos_coletados()) {
    DrawRectangle(50, 850, 1200, 60, (Color){0,0,0,200});
    DrawText("Encontre os 4 fragmentos antes de me responder!", 70, 865, 18, WHITE);
}


if(Proximo_ao_Bau(player.x, player.y) && todos_coletados() && !bau.chave_entregue) {
    DrawRectangle(50, 850, 1200, 60, (Color){0,0,0,200});
    DrawText("[E] Responder a charada do bau", 70, 865, 18, GOLD);
}


Interacao_Bau(player.x, player.y, todos_coletados() ? 4 : 0, &vidas, &tem_chave);

if(venceu) {
    DrawRectangle(0, 0, 1300, 1000, (Color){0, 0, 0, 220});
    DrawText("VOCE ESCAPOU!", 400, 350, 48, GOLD);
    DrawText("A Chave do Abismo foi conquistada!", 280, 430, 24, WHITE);
    DrawText("[ENTER] Jogar novamente  [ESC] Sair", 300, 520, 20, GRAY);

    if(IsKeyPressed(KEY_ENTER)) {
        venceu = 0;
        tem_chave = 0;
        InitBau();
        InitPlayer(&player);
    }
}
            DrawFPS(10, 10);

           

        EndDrawing();
    }

    DescarregarPorta();
    DescarregarBau();
    descarregar_mapa();
    CloseWindow();

    return 0;
}




