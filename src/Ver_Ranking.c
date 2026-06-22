
#include "Ranking.h"
#include "raylib.h"
#include <stdio.h>
#include <string.h>
#include "Ranking.h"
extern Font fonte_texto;

struct Players {

      double seu_tempo;
      char seu_nome[30];
      int seus_coracoes;

};

void Ranking_leitura ( ){

      int j, pos,  contador= 0; 
    
    char linha[200], lixo [150];

    struct Players players[10];

    int i= 0 ;

    FILE *arquivo;

    arquivo =  fopen("C:\\Users\\Mateu\\Projeto jogo\\Ranking_jogo.txt", "r");

    if(arquivo == NULL){
        printf("arquivo nao encontrado\n");
        return ;
    }

    DrawRectangle(0, 0, 1300, 1000, BLACK);
    
    
   while(fgets(linha, sizeof(linha), arquivo) != NULL){

    if(sscanf(linha,"%d;%24[^;];%lf;%d",&pos, players[contador].seu_nome,  &players[contador].seu_tempo,  &players[contador].seus_coracoes) == 4){

        

        contador++;
        
          if(contador == 10){
            break;
        } 
        
      
    }  
}

 fclose(arquivo);

    DrawTextEx(fonte_texto,"__________________________RANKING________________________\n" 
             "Pos          Nome                 Tempo_gasto       Vidas\n", (Vector2){100, 50}, 30, 1,  WHITE);
    

  for(i = 0; i < contador; i++)
{
    DrawTextEx(fonte_texto,
               TextFormat("%d", i+1),
               (Vector2){100, 140+80*i},
               30, 1, GOLD);

    DrawTextEx(fonte_texto,
               players[i].seu_nome,
               (Vector2){240, 140+80*i},
               30, 1, WHITE);

    DrawTextEx(fonte_texto,
               TextFormat("%.2lfs", players[i].seu_tempo),
               (Vector2){800, 140+80*i},
               30, 1, BLUE);

    DrawTextEx(fonte_texto,
               TextFormat("%d", players[i].seus_coracoes),
               (Vector2){1110, 140+80*i},
               30, 1, RED);
}

    
   
    return ; 

   

}