#include "Ranking.h"
#include "raylib.h"
#include <stdio.h>
#include <string.h>

struct Players
{

    double seu_tempo;
    char seu_nome[30];
    int seus_coracoes;
};

void Ranking(double tempo, char nome[30], int coracoes)
{

    int i, j, pos, contador = 0;

    char linha[200];

    struct Players players[10], novo_player, aux;

    FILE *arquivo;

    arquivo = fopen("C:\\Users\\Mateu\\Projeto jogo\\Ranking_jogo.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    strcpy(novo_player.seu_nome, nome);
    novo_player.seu_tempo = tempo;
    novo_player.seus_coracoes = coracoes;

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {

        if (sscanf(linha, "%d;%24[^;];%lf;%d", &pos, players[contador].seu_nome, &players[contador].seu_tempo, &players[contador].seus_coracoes) == 4)
        {

            contador++;

            if (contador == 10)
            {
                break;
            }
        }
    }

    for (i = 0; i < contador - 1; i++)
    {
        for (j = 0; j < contador - 1 - i; j++)
        {

            if (players[j].seu_tempo > players[j + 1].seu_tempo)
            {

                aux = players[j];
                players[j] = players[j + 1];
                players[j + 1] = aux;
            }

            else if (players[j].seu_tempo == players[j + 1].seu_tempo &&
                     players[j].seus_coracoes < players[j + 1].seus_coracoes)
            {

                aux = players[j];
                players[j] = players[j + 1];
                players[j + 1] = aux;
            }
        }
    }

    fclose(arquivo);

    arquivo = fopen("C:\\Users\\Mateu\\Projeto jogo\\Ranking_jogo.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    if (contador < 10)
    {
        players[contador] = novo_player;
        contador++;
    }
    else if (novo_player.seu_tempo < players[contador - 1].seu_tempo)
    {

        players[contador - 1] = novo_player;
    }
    else if (novo_player.seu_tempo == players[contador - 1].seu_tempo && novo_player.seus_coracoes > players[contador - 1].seus_coracoes)
    {

        players[contador - 1] = novo_player;
    }

    for (i = 0; i < contador - 1; i++)
    {

        for (j = 0; j < contador - 1 - i; j++)
        {

            if (players[j].seu_tempo > players[j + 1].seu_tempo)
            {

                aux = players[j];
                players[j] = players[j + 1];
                players[j + 1] = aux;
            }

            else if (players[j].seu_tempo == players[j + 1].seu_tempo &&
                     players[j].seus_coracoes < players[j + 1].seus_coracoes)
            {

                aux = players[j];
                players[j] = players[j + 1];
                players[j + 1] = aux;
            }
        }
    }

    for (i = 0; i < contador; i++)
    {
        fprintf(arquivo,

                "%d;%s;%.2lf;%d\n",
                i + 1,
                players[i].seu_nome,
                players[i].seu_tempo,
                players[i].seus_coracoes);
    }

    fclose(arquivo);
    return;
}
