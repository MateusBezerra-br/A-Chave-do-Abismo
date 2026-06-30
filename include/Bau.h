#ifndef BAU_H
#define BAU_H

#define RAIO_BAU 25.0f

typedef struct {

    float x;
    float y;
    

} Bau;

extern Bau bau;

void DrawBau( );

void InitBau( );

void Interacao_Bau(float px, float py, int fragmentos_coletados, int *vidas, int *mostrar_chave, Sound dano, Sound correta);

int Proximo_ao_Bau(float px, float py );

int esta_na_charada();

void DescarregarBau();

#endif