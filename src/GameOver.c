#include "raylib.h"
#include "Gameover.h"
#include "Player.h"
#include "Chave.h"
#include "Papeis.h"

extern Font fonte_texto;


void GameOver(Player *player,int spawn_chave)
{

    if (player->vidas == 0)
    {
        DrawRectangle(0, 0, 1500, 1000, BLACK);

        DrawTextEx(fonte_texto, "GAME OVER", (Vector2){470, 350}, 100, 1, RED);
        DrawTextEx(fonte_texto, "[ENTER] Jogar novamente", (Vector2){580, 520}, 20, 1, YELLOW);

        player->x = 100000;

        if (IsKeyPressed(KEY_ENTER))
        {
            int i;

            player->vidas = 4;
            spawn_chave = 0;
        

            for (i = 0; i < 4; i++)
            {
                papeis[i].coletado = 1;
            }

            InitPlayer(player);
            InitPapeis();
            InitBau();
           
        }
    }
}
