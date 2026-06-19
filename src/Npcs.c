#include "Npcs.h"
#include "raylib.h"
#include "Mapa.h"
#include <stdio.h>
#include <Math.h>
#include "Bau.h"



int j;

Npc npcs[23];

static Texture2D textura_npcs;


void InitNpc()
{
    npcs[0].spawnX = 900;
    npcs[0].spawnY = 1310;
    npcs[1].spawnX = 469;
    npcs[1].spawnY = 850;
    npcs[2].spawnX = 330;
    npcs[2].spawnY = 498;
    npcs[3].spawnX = 1248;
    npcs[3].spawnY = 950;
    npcs[4].spawnX = 1048;
    npcs[4].spawnY = 590;
    npcs[5].spawnX = 600;
    npcs[5].spawnY = 865;
    npcs[6].spawnX = 348;
    npcs[6].spawnY = 1160;
    npcs[7].spawnX = 648;
    npcs[7].spawnY = 1515;
    npcs[8].spawnX = 148;
    npcs[8].spawnY = 620;
    npcs[9].spawnX = 148;
    npcs[9].spawnY = 500;
    npcs[10].spawnX = 1000;
    npcs[10].spawnY = 1033;
    npcs[11].spawnX = 1120;
    npcs[11].spawnY = 450;
    npcs[12].spawnX = 963;
    npcs[12].spawnY = 550;
    npcs[13].spawnX = 1348;
    npcs[13].spawnY = 720;
    npcs[14].spawnX = 1348;
    npcs[14].spawnY = 1050;
    npcs[15].spawnX = 1208;
    npcs[15].spawnY = 1520;
    npcs[16].spawnX = 800;
    npcs[16].spawnY = 265;
    npcs[17].spawnX = 644;
    npcs[17].spawnY = 136;
    npcs[18].spawnX = 844;
    npcs[18].spawnY = 1166;
    npcs[19].spawnX = 500;
    npcs[19].spawnY = 1166;
    npcs[20].spawnX = 1258;
    npcs[20].spawnY = 470;



    npcs[0].x =     npcs[0].spawnX ;
    npcs[0].y =     npcs[0].spawnY ;
    npcs[1].x =     npcs[1].spawnX ;
    npcs[1].y =     npcs[1].spawnY ;
    npcs[2].x =     npcs[2].spawnX ;
    npcs[2].y =     npcs[2].spawnY ;
    npcs[3].x =     npcs[3].spawnX ;
    npcs[3].y =     npcs[3].spawnY ;
    npcs[4].x =     npcs[4].spawnX ;
    npcs[4].y =     npcs[4].spawnY ;
    npcs[5].x =     npcs[5].spawnX ;
    npcs[5].y =     npcs[5].spawnY ;
    npcs[6].x =     npcs[6].spawnX ;
    npcs[6].y =     npcs[6].spawnY ;
    npcs[7].x =     npcs[7].spawnX ;
    npcs[7].y =     npcs[7].spawnY ;
    npcs[8].x =     npcs[8].spawnX ;
    npcs[8].y =     npcs[8].spawnY ;
    npcs[9].x =     npcs[9].spawnX ;
    npcs[9].y =     npcs[9].spawnY ;
    npcs[10].x =     npcs[10].spawnX ;
    npcs[10].y =     npcs[10].spawnY ;
    npcs[11].x =     npcs[11].spawnX ;
    npcs[11].y =     npcs[11].spawnY ;
    npcs[12].x =     npcs[12].spawnX ;
    npcs[12].y =     npcs[12].spawnY ;
    npcs[13].x =     npcs[13].spawnX ;
    npcs[13].y =     npcs[13].spawnY ;
    npcs[14].x =     npcs[14].spawnX ;
    npcs[14].y =     npcs[14].spawnY ;
    npcs[15].x =     npcs[15].spawnX ;
    npcs[15].y =     npcs[15].spawnY ;
    npcs[16].x =     npcs[16].spawnX ;
    npcs[16].y =     npcs[16].spawnY ;
    npcs[17].x =     npcs[17].spawnX ;
    npcs[17].y =     npcs[17].spawnY ;
    npcs[18].x =     npcs[18].spawnX ;
    npcs[18].y =     npcs[18].spawnY ;
    npcs[19].x =     npcs[19].spawnX ;
    npcs[19].y =     npcs[19].spawnY ;
    npcs[20].x =     npcs[20].spawnX ;
    npcs[20].y =     npcs[20].spawnY ;

      textura_npcs = LoadTexture("assets/space.png");

    for(j= 0; j < 21; j++){
        npcs[j].veloc = 1.6;
        npcs[j].direcao= 1;
        npcs[j].estado = PATRULHANDO;
        npcs[j].visao = 39;
    }
};



void UpdateNpcs(float playerX, float playerY, int *vidas){

   

     for(j=0; j < 21; j++){
        
      npcs[j].distancia =  sqrt(pow((npcs[j].x - playerX), 2) + pow((npcs[j].y - playerY), 2) );
    }



     for(j = 0; j < 21; j++) {

    
    if(npcs[j].estado == PATRULHANDO){
    if(j == 0 || j == 2 || j == 4 || j == 5 || j == 6 || j == 7 || j == 8 || j == 9 || j == 10 || j == 13 || j == 15 || j == 16 || j == 17 || j == 18 || j == 20){
    npcs[j].x += npcs[j].direcao * npcs[j].veloc;
    }
    else if(j == 1 || j == 3 || j == 11 || j == 12 || j == 14 || j == 19){
     npcs[j].y += npcs[j].direcao * npcs[j].veloc;
    }



    if(npcs[0].x > npcs[0].spawnX + 370){

        npcs[0].direcao = -1;

    }
    if(npcs[0].x < npcs[0].spawnX - 388){

        npcs[0].direcao = 1;

    }

    if(npcs[1].y > npcs[1].spawnY + 145){

        npcs[1].direcao = -1;

    }
    if(npcs[1].y < npcs[1].spawnY - 375){

        npcs[1].direcao = 1;

    }

     if(npcs[2].x > npcs[2].spawnX + 320){

        npcs[2].direcao = -1;

    }
    if(npcs[2].x < npcs[2].spawnX - 17){

        npcs[2].direcao = 1;

    }

    if(npcs[3].y > npcs[3].spawnY + 560){

        npcs[3].direcao = -1;

    }
    if(npcs[3].y < npcs[3].spawnY - 450){

        npcs[3].direcao = 1;

    }

    if(npcs[4].x > npcs[4].spawnX + 208){

        npcs[4].direcao = -1;

    }
    if(npcs[4].x < npcs[4].spawnX - 475){

        npcs[4].direcao = 1;

    }

     if(npcs[5].x > npcs[5].spawnX + 400){

        npcs[5].direcao = -1;

    }
    if(npcs[5].x < npcs[5].spawnX - 35){

        npcs[5].direcao = 1;

    }

     if(npcs[6].x > npcs[6].spawnX + 55){

        npcs[6].direcao = -1;

    }
    if(npcs[6].x < npcs[6].spawnX - 270){

        npcs[6].direcao = 1;

    }

     if(npcs[7].x > npcs[7].spawnX + 270){

        npcs[7].direcao = -1;

    }
    if(npcs[7].x < npcs[7].spawnX - 380){

        npcs[7].direcao = 1;

    }

    if(npcs[8].x > npcs[8].spawnX + 80){

        npcs[8].direcao = -1;

    }
    if(npcs[8].x < npcs[8].spawnX - 87){

        npcs[8].direcao = 1;

    }

    if(npcs[9].x > npcs[9].spawnX + 80){

        npcs[9].direcao = -1;

    }
    if(npcs[9].x < npcs[9].spawnX - 87){

        npcs[9].direcao = 1;

    }
    if(npcs[10].x > npcs[10].spawnX + 400){

        npcs[10].direcao = -1;

    }
    if(npcs[10].x < npcs[10].spawnX - 267){

        npcs[10].direcao = 1;

    }
    if(npcs[11].y > npcs[11].spawnY + 40){

        npcs[11].direcao = -1;

    }
    if(npcs[11].y < npcs[11].spawnY - 150){

        npcs[11].direcao = 1;

    }
     if(npcs[12].y > npcs[12].spawnY + 185){

        npcs[12].direcao = -1;

    }
    if(npcs[12].y < npcs[12].spawnY - 100){

        npcs[12].direcao = 1;

    }
    if(npcs[13].x > npcs[13].spawnX + 130){

        npcs[13].direcao = -1;

    }
    if(npcs[13].x < npcs[13].spawnX - 125){

        npcs[13].direcao = 1;

    }

    if(npcs[14].y > npcs[14].spawnY + 10){

        npcs[14].direcao = -1;

    }
    if(npcs[14].y < npcs[14].spawnY - 233){

        npcs[14].direcao = 1;

    }

     if(npcs[15].x > npcs[15].spawnX + 300){

        npcs[15].direcao = -1;

    }
    if(npcs[15].x < npcs[15].spawnX - 130){

        npcs[15].direcao = 1;

    }
    if(npcs[16].x > npcs[16].spawnX + 7){

        npcs[16].direcao = -1;

    }
    if(npcs[16].x < npcs[16].spawnX - 172){

        npcs[16].direcao = 1;

    }

    if(npcs[17].x > npcs[17].spawnX + 16){

        npcs[17].direcao = -1;

    }
    if(npcs[17].x < npcs[17].spawnX -139){

        npcs[17].direcao = 1;

    }
    if(npcs[18].x > npcs[18].spawnX + 200){

        npcs[18].direcao = -1;

    }
    if(npcs[18].x < npcs[18].spawnX -99){

        npcs[18].direcao = 1;

    }
     if(npcs[19].y > npcs[19].spawnY + 340){

        npcs[19].direcao = -1;

    }
    if(npcs[19].y < npcs[19].spawnY -80){

        npcs[19].direcao = 1;

    }
     if(npcs[20].x > npcs[20].spawnX + 230){

        npcs[20].direcao = -1;

    }
    if(npcs[20].x < npcs[20].spawnX - 15){

        npcs[20].direcao = 1;

    }

    }
    
     if(npcs[j].distancia < npcs[j].visao){
        npcs[j].estado = PERSEGUINDO;

        npcs[j].visao = 60;
       

            if(playerX > npcs[j].x){
                npcs[j].x += 1.2;
            }
            if(playerX < npcs[j].x){
                npcs[j].x -= 1.2;
            }
            if(playerY > npcs[j].y){
                npcs[j].y += 1.2;
            }
            if(playerY < npcs[j].y){
                npcs[j].y -= 1.2;
            }
            if(IsKeyPressed(KEY_F) ){
    printf("%.2f\n",npcs[j].distancia);
    }
        
        
            
    }

    


    if(npcs[j].distancia >= npcs[j].visao && npcs[j].estado == PERSEGUINDO || npcs[j].distancia <= 3.5 && npcs[j].estado == PERSEGUINDO){
                npcs[j].estado = RESPAWN;
                npcs[j].tempoRespawn = 3.f;

                npcs[j].x =  1000; 
                npcs[j].y =  10000;
            }
   

    if(npcs[j].estado == RESPAWN){

        npcs[j].tempoRespawn -= GetFrameTime();

        if(npcs[j].distancia <= 3.5){

            *vidas -= 1;
           
        }
        if(npcs[j].tempoRespawn <= 0){

            npcs[j].estado = PATRULHANDO;

                npcs[j].visao = 40;

                npcs[j].x =  npcs[j].spawnX; 
                npcs[j].y =  npcs[j].spawnY;

        }
    }
   
    

 }

};

void DrawNpcs() {
    for(j = 0; j < 21; j++) {
       
       
     
    
       
        DrawTextureEx(
            textura_npcs,
            (Vector2){npcs[j].x -6 ,npcs[j].y -6},
            0.0f,   
            0.024f,   
            WHITE
        );
    
        
        
    }
}

void DescarregarNpcs()
{

        UnloadTexture(textura_npcs);
        
};
