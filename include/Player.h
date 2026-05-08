#ifndef PLAYER_H
#define PLAYER_H


typedef struct {

    float x;
    float y;
    
    int veloc;
    
    int raio;
    
} Player;

void InitPlayer(Player *p);

void UpdatePlayer(Player *p);

void DrawPlayer(Player *p);

int Colisaoparede(float x, float y, float raio);


#endif  