#include "raylib.h"
#include "Player.h"

int main(void) {

    // Abre a janela com titulo e tamanho
    InitWindow(1100, 700, "A Chave do Abismo — Raylib funcionando!");

    // Trava em 60 quadros por segundo
    SetTargetFPS(60);

     Player player;
    InitPlayer(&player);
    

    while (!WindowShouldClose()) {

        void InitPlayer(Player *p);

        UpdatePlayer(&player);

        BeginDrawing();

            ClearBackground(WHITE);

            DrawPlayer(&player);
            

            
            DrawFPS(10, 10);

        EndDrawing();
    }

    // Fecha a janela e libera recursos
    CloseWindow();

    return 0;
}




