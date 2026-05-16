#include "raylib.h"
#include "Player.h"
#include "Mapa.h"
#include "Camera.h"
#include "Ball.h"

int main(void) {

    
    InitWindow(1300, 1000, "A Chave do Abismo");
     SetTargetFPS(60);
    
    carregar_mapa();


     Player player;
    InitPlayer(&player);
    
    

Camera2D camera = {0};

InitCamera(&camera, &player);

Ball balls[1];

InitBall(&balls[0], player.x + 30, player.y, 0, 0); 



    while (!WindowShouldClose()) {

        for (int i = 0; i < 1; i++) {
            UpdateBall(&balls[i]);
        }

        UpdatePlayer(&player);

        AtualizarCamera(&camera, &player);

        BeginDrawing();

        ClearBackground(BLACK);
        
        BeginMode2D(camera);

            
            camera.target = (Vector2){player.x, player.y};
            
            desenhar_mapa();

              for (int i = 0; i < 1; i++) {
            DrawBall(&balls[i]);
        }

            DrawPlayer(&player);
            
             EndMode2D();

            DrawFPS(10, 10);

           

        EndDrawing();
    }

    descarregar_mapa();
    CloseWindow();

    return 0;
}




