#include "raylib.h"

int main(void) {

    // Abre a janela com titulo e tamanho
    InitWindow(1100, 700, "A Chave do Abismo — Raylib funcionando!");

    // Trava em 60 quadros por segundo
    SetTargetFPS(60);

    // Loop principal: roda ate fechar a janela ou pressionar ESC
    while (!WindowShouldClose()) {

        BeginDrawing();

            ClearBackground(BLACK);

            DrawText("Raylib funcionando!", 400, 350, 36, YELLOW);
            DrawText("Pressione ESC para fechar", 400, 310, 18, LIGHTGRAY);

            // Mostra o FPS no canto superior esquerdo
            DrawFPS(10, 10);

        EndDrawing();
    }

    // Fecha a janela e libera recursos
    CloseWindow();

    return 0;
}




