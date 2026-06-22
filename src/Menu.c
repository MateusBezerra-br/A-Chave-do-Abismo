#include "raylib.h"
#include <stdio.h>

void RunMenu(void)
{
    Texture2D menu = LoadTexture("assets/menu.png");

    printf("Largura: %d\n", menu.width);
    printf("Altura: %d\n", menu.height);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawTexture(menu, 0, 0, WHITE);

        EndDrawing();

        if (IsKeyPressed(KEY_ENTER))
            break;
    }

    UnloadTexture(menu);
}