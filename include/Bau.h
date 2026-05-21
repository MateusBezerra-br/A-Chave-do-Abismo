#ifndef BAU_H
#define BAU_H

#define RAIO_BAU 25.0f
typedef struct {

    float x;
    float y;
    int chave_entregue;

} Bau;

extern Bau bau;
void DrawBau( );

void InitBau( );

void Interacao_Bau(float px, float py, int fragmentos_coletados, int *vidas, int *tem_chave );

int Proximo_ao_Bau(float px, float py );

int esta_na_charada();

void DescarregarBau();

#endif