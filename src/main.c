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

Ball balls[4];

InitBall(&balls[0], 156, 1481, 150, 0); 
InitBall(&balls[1], 1477, 1230, 0, 150); 
InitBall(&balls[2], 1187, 109, -150, 0); 
InitBall(&balls[3], 767, 250, 0, -150); 



    while (!WindowShouldClose()) {

        for (int i = 0; i < 4; i++) {
            UpdateBall(&balls[i]);
        }

        UpdatePlayer(&player);

        AtualizarCamera(&camera, &player);

        BeginDrawing();

        ClearBackground(BLACK);
        
        BeginMode2D(camera);

            
            camera.target = (Vector2){player.x, player.y};
            
            desenhar_mapa();

              for (int i = 0; i < 4; i++) {
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




