#include "Camera.h"

void InitCamera(Camera2D *camera, Player *player) {

    camera->target = (Vector2){player->x, player->y};

    camera->offset = (Vector2){1450 / 2.0f, 1000 / 2.0f};

    camera->rotation = 0.0f;

    camera->zoom = 9.f;
}

void AtualizarCamera(Camera2D *camera, Player *player) {

    camera->target = (Vector2){player->x, player->y};
}