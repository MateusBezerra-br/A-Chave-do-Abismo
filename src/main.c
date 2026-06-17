#include "raylib.h"
#include "Player.h"
#include "Mapa.h"
#include "Camera.h"
#include "Ball.h"
#include <stdio.h>

int main(void) {

    
    InitWindow(1300, 1000, "A Chave do Abismo");
     SetTargetFPS(60);
    
    carregar_mapa();


     Player player;
    InitPlayer(&player);
    
    

Camera2D camera = {0};

InitCamera(&camera, &player);

Ball balls[7];

InitBall(&balls[0], 156, 1481, 200, 0); 
InitBall(&balls[1], 1540, 1160, 100, 120); 
InitBall(&balls[2], 1187, 109, -200, 0); 
InitBall(&balls[3], 131, 227, 120, 40); 
InitBall(&balls[4], 801, 864, 150, 0);
InitBall(&balls[5], 354, 863, 0, 220);
InitBall(&balls[6], 915, 290, 100, 0);

    while (!WindowShouldClose()) {

        for (int i = 0; i < 7; i++) {
            UpdateBall(&balls[i]);
        }

        UpdatePlayer(&player);

        AtualizarCamera(&camera, &player);

        BeginDrawing();

        ClearBackground(BLACK);
        
        BeginMode2D(camera);

            
            camera.target = (Vector2){player.x, player.y};
            
            desenhar_mapa();

              for (int i = 0; i < 7; i++) {
            DrawBall(&balls[i]);



   }

            DrawPlayer(&player);
            
            

             EndMode2D();
             
             DrawText(TextFormat("X: %.0f", player.x), 20, 20, 20, RED);
DrawText(TextFormat("Y: %.0f", player.y), 20, 45, 20, RED);
            
            
            DrawFPS(10, 10);

           

        EndDrawing();
    }

    descarregar_mapa();
    CloseWindow();

    return 0;
}




