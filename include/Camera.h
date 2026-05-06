#ifndef CAMERA_H
#define CAMERA_H

#include "raylib.h"
#include "Player.h"

void InitCamera(Camera2D *camera, Player *player);

void AtualizarCamera(Camera2D *camera, Player *player);

#endif