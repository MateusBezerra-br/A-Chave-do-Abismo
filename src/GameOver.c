#include "raylib.h"
#include "Gameover.h"
#include "Player.h"


extern Font fonte_texto;

#include "Papeis.h"

void GameOver(Player *player, int *chave){
    
    if(player->vidas == 0)
    {
        DrawRectangle(0, 0, 1300, 1000, BLACK);

        DrawTextEx(fonte_texto,"GAME OVER",(Vector2){400,350},70,1,RED);
        DrawTextEx(fonte_texto,"[ENTER] Jogar novamente", (Vector2){440, 520}, 20, 1, YELLOW);

        player->x = 100000;

        if(IsKeyPressed(KEY_ENTER))
        {
            int i;

            player->vidas = 4;
            *chave = 0;

            for(i = 0; i < 4; i++)
            {
                papeis[i].coletado = 1;
            }

            InitPlayer(player);
            InitPapeis();
            InitBau();
        }
    }
}



