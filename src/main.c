#include "raylib.h"
#include "Player.h"
#include "Mapa.h"


int main(void) {

    
    InitWindow(1300, 1000, "A Chave do Abismo");
     SetTargetFPS(60);
    
    carregar_mapa();


     Player player;
    InitPlayer(&player);
    

    while (!WindowShouldClose()) {

        void InitPlayer(Player *p);

        UpdatePlayer(&player);

        BeginDrawing();
            
            ClearBackground(BLACK);
            
            desenhar_mapa();

            DrawPlayer(&player);
            

            DrawFPS(10, 10);

        EndDrawing();
    }

    descarregar_mapa();
    CloseWindow();

    return 0;
}




