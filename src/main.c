#include "raylib.h"
#include "Player.h"
#include "Mapa.h"
#include "Camera.h"

int main(void) {

    
    InitWindow(1300, 1000, "A Chave do Abismo");
     SetTargetFPS(60);
    
    carregar_mapa();


     Player player;
    InitPlayer(&player);
    
    

Camera2D camera = {0};

InitCamera(&camera, &player);


    while (!WindowShouldClose()) {


        UpdatePlayer(&player);

        AtualizarCamera(&camera, &player);

        BeginDrawing();

        ClearBackground(BLACK);
        
        BeginMode2D(camera);

            
            camera.target = (Vector2){player.x, player.y};
            
            desenhar_mapa();

            DrawPlayer(&player);
            
             EndMode2D();

            DrawFPS(10, 10);

           

        EndDrawing();
    }

    descarregar_mapa();
    CloseWindow();

    return 0;
}




