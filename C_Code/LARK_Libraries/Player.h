#ifndef PLAYER_H
#define PLAYER_H
#include <stdbool.h>
#include "../MikeEngine/Engine.h"

extern float movementSpeed;
extern float rotateSpeed;

//processes commands such as ls, cd, cat, man, jobs, kill
void ProcessCommand(char command[32]);

//what the player does every update
void OnPlayerUpdate();

#endif