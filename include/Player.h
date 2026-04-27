#ifndef PLAYER_H
#define PLAYER_H


typedef struct {

    int x;
    int y;
    
    int veloc;
    
    int raio;
    
} Player;

void InitPlayer(Player *p);

void UpdatePlayer(Player *p);

void DrawPlayer(Player *p);

#endif  