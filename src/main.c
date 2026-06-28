#include "raylib.h"
#include "Player.h"
#include "Mapa.h"
#include "Camera.h"
#include "Bau.h"
#include "Porta.h"
#include "Papeis.h"
#include "Npcs.h"
#include <stdio.h>
#include "Ball.h"
#include "GameOver.h"
#include "string.h"
#include "Ranking.h"
#include "Ver_Ranking.h"
#include "Menu.h"
#include "Chave.h"

 

int todos_coletados()
{
    int i;
    for (i = 0; i < 4; i++)
    {

        if (papeis[i].coletado == 1)
        {

            return 1;
        }
    }

    return 1;
};

Font fonte_texto;

int main(void)
{

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(1500, 1000, "A Chave do Abismo");
    SetExitKey(KEY_DOWN);
    SetTargetFPS(60);
    

    carregar_mapa();

    Player player;
    InitPlayer(&player);

    InitBau();

    int chave_aparece = 0;
    
    int venceu = 0;

    InitPorta();
    InitPapeis();
    InitNpc();

    
    InitChave(chave_aparece );
    
    
    
    Texture2D Tela_vitoria = LoadTexture("assets/tela_vitoria.png");
    fonte_texto = LoadFontEx("assets/bedstead-bold.otf", 32, 0, 500);
    SetTextureFilter(fonte_texto.texture, TEXTURE_FILTER_POINT);

    Camera2D camera = {0};

    InitCamera(&camera, &player);

    Ball balls[7];

    InitBall(&balls[0], 156, 1481, 180, 0);
    InitBall(&balls[1], 1540, 1160, 80, 100);
    InitBall(&balls[2], 1187, 109, -210, 0);
    InitBall(&balls[3], 131, 227, -110, -45);
    InitBall(&balls[4], 1187, 109, 0, 210);
    InitBall(&balls[5], 131, 227, 160, 0);
    InitBall(&balls[6], 1520, 1160, -120, -130);

    balls[0].checkX = 135;
    balls[0].checkY = 1365;
    balls[1].checkX = 1508;
    balls[1].checkY = 1400;
    balls[2].checkX = 1049;
    balls[2].checkY = 159;
    balls[3].checkX = 200;
    balls[3].checkY = 361;
    balls[4].checkX = 1049;
    balls[4].checkY = 159;
    balls[5].checkX = 200;
    balls[5].checkY = 365;
    balls[6].checkX = 1508;
    balls[6].checkY = 1400;

    extern int errado;
    double time_inicial = GetTime();
    int vitoria = 0;
    char nome[25];
    int tam = 0;
    
    double time_gameplay = GetTime() - time_inicial;

    

      RunMenu();

    while (!WindowShouldClose())
    {

       
      
       
        
        for (int i = 0; i < 7; i++)
        {
            UpdateBall(&balls[i], &player.vidas, player.x, player.y, &player);
        }

        AtualizarCamera(&camera, &player);

        if (!esta_na_charada())
            UpdatePlayer(&player);

        Verificar_papel(player.x, player.y);
        Verificar_Chave(player.x, player.y, chave_aparece );
        UpdateNpcs(player.x, player.y, &player.vidas);

        BeginDrawing();

        ClearBackground(BLACK);

        BeginMode2D(camera);

        camera.target = (Vector2){player.x, player.y};

        desenhar_mapa();

        for (int i = 0; i < 7; i++)
        {
            DrawBall(&balls[i]);
        }

        DrawPlayer(&player);
        DrawBau();
        DrawPorta();
        Drawpapeis();
        DrawNpcs();

     
        DrawChave(chave_aparece );
       
        
        

        EndMode2D();

        for (int i = 0; i < 4; i++)
        {
            Color cor = (i < player.vidas) ? RED : DARKGRAY;
            DrawCircle(30 + i * 40, 30, 14, cor);
        }

        verificar_porta(player.x, player.y, chave.coletada, &venceu);

        float dx = player.x - porta.x;
        float dy = player.y - porta.y;

        if (dx * dx + dy * dy < 200 && !chave.coletada)
        {
            DrawRectangle(50, 850, 1200, 60, (Color){0, 0, 0, 200});
            DrawTextEx(fonte_texto, "Voce precisa da chave para sair daqui!", (Vector2){70, 865}, 24, 1, (Color){180, 106, 79, 255});
        }

        if (Proximo_ao_Bau(player.x, player.y) && !todos_coletados())
        {
            DrawRectangle(50, 850, 1200, 60, (Color){0, 0, 0, 200});
            DrawTextEx(fonte_texto, "Encontre os 4 fragmentos para responder a charada!", (Vector2){70, 865}, 24, 1, WHITE);
        }

        if (Proximo_ao_Bau(player.x, player.y) && todos_coletados() &&  !chave_aparece)
        {
            DrawRectangle(50, 850, 1200, 60, (Color){0, 0, 0, 200});
            DrawTextEx(fonte_texto, "[ E ] Responder a charada do bau", (Vector2){70, 865}, 24, 1, GOLD);
        }

        Interacao_Bau(player.x, player.y, todos_coletados() ? 4 : 0, &player.vidas, &chave_aparece);

        if (!venceu)
        {
            time_gameplay = GetTime() - time_inicial;
        }
        
        if (venceu)
        {

            DrawTexturePro(
                Tela_vitoria,
                (Rectangle){0, 0, Tela_vitoria.width, Tela_vitoria.height},
                (Rectangle){0, 0, 1500, 1000},
                (Vector2){0, 0},
                0.0f,
                WHITE);

            DrawTextEx(fonte_texto, "Tecle dois para digitar seu nome", (Vector2){455, 890}, 31, 1, WHITE);

            player.x = 772;
            player.y = 768;

            if (IsKeyReleased(KEY_TWO))
            {
                vitoria = 1;
            }
            if (vitoria == 1)
            {

                int tecla = GetCharPressed();

                while (tecla > 0)
                {

                    if (tecla >= 32 && tecla <= 125 && tam < 24)
                    {
                        nome[tam] = (char)tecla;
                        tam++;
                        nome[tam] = '\0';
                    }

                    tecla = GetCharPressed();
                }
                if (GetCharPressed() && tam > 0)
                {
                    tam++;
                    nome[tam] = '\0';
                }
                if (IsKeyPressed(KEY_BACKSPACE) && tam > 0)
                {
                    tam--;
                    nome[tam] = '\0';
                }
                if (IsKeyReleased(KEY_ENTER))
                {

                    Ranking(time_gameplay, nome, player.vidas);
                    break;

                }
               

                DrawRectangle(0, 0, 1500, 1000, BLACK);

                DrawTextEx(fonte_texto,
                           "Digite seu nome:",
                           (Vector2){490, 300},
                           40, 1, GOLD);

                DrawTextEx(fonte_texto,
                           nome,
                           (Vector2){465, 400},
                           35, 1, WHITE);

                DrawTextEx(fonte_texto, "[ ENTER ] CONFIRMAR", (Vector2){550, 500}, 30, 1, PURPLE);
            }
        }
        if (player.vidas <= 0)
        {

            GameOver(&player, chave_aparece);

            if (IsKeyPressed(KEY_ENTER))
            {
                time_inicial = GetTime();
                time_gameplay = 0;
                chave_aparece = 0;
            }
        }

        DrawText(TextFormat("X: %.0f", player.x), 10, 935, 20, WHITE);
        DrawText(TextFormat("Y: %.0f", player.y), 10, 955, 20, WHITE);
        DrawText(TextFormat("tempo: %.2lf", time_gameplay), 10, 975, 20, WHITE);

        EndDrawing();
    }

    UnloadFont(fonte_texto);
    DescarregarChave();
    DescarregarNpcs();
    DescarregarPapel();
    DescarregarPorta();
    DescarregarBau();
    descarregar_mapa();
    CloseWindow();

    return 0;
}
