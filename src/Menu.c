#include "raylib.h"
#include "Ver_Ranking.h"

int estado = 0;

void RunMenu(void)
{
    Texture2D menu = LoadTexture("assets/menu.png");
    Texture2D Tela_ranking = LoadTexture("assets/tela_ranking.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawTexturePro(
            menu,
            (Rectangle){0, 0, menu.width, menu.height},
            (Rectangle){0, 0, 1500, 1000},
            (Vector2){0, 0},
            0.0f,
            WHITE);

        DrawText(
            "ENTER - JOGAR",
            650,
            835,
            24,
            WHITE);
        DrawText(
            "THREE - VER RANKING",
            650,
            885,
            24,
            WHITE);

        if (IsKeyPressed(KEY_THREE))
        {
            estado = 1;
        }
        if (estado == 1)
        {

            DrawTexturePro(
                Tela_ranking,
                (Rectangle){0, 0, Tela_ranking.width, Tela_ranking.height},
                (Rectangle){0, 0, 1500, 1000},
                (Vector2){0, 0},
                0.0f,
                WHITE);

            Ranking_leitura();
        }
        if (IsKeyPressed(KEY_ESCAPE))
        {
            estado = 0;
        }

        EndDrawing();

        if (IsKeyPressed(KEY_ENTER)){
            break;
        }
    }
    UnloadTexture(Tela_ranking);
    UnloadTexture(menu);
}