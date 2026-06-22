#include "raylib.h"

void RunMenu(void)
{
    Texture2D menu = LoadTexture("assets/menu.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawTexturePro(
            menu,
            (Rectangle){0, 0, menu.width, menu.height},
            (Rectangle){0, 0, 1300, 1000},
            (Vector2){0, 0},
            0.0f,
            WHITE
        );

        DrawText(
            "ENTER - JOGAR",
            540,
            835,
            24,
            WHITE
        );

        EndDrawing();

        if (IsKeyPressed(KEY_ENTER))
            break;
    }

    UnloadTexture(menu);
}