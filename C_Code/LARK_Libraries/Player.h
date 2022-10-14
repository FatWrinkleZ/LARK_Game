#ifndef PLAYER_H
#define PLAYER_H
#include <stdbool.h>
#include "../MikeEngine/Engine.h"

extern float movementSpeed;
extern float rotateSpeed;

void ProcessCommand(char command[32]);

void OnPlayerUpdate();

#endif