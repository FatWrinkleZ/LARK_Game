#ifndef PLAYER_H
#define PLAYER_H
#include "engine_man.h"
#include <dirent.h>
#include <stdbool.h>
#include "../MikeEngine/Engine.h"

extern float movementSpeed;
extern float rotateSpeed;

//outputs all files in the LEVELS directory
void LS();

//processes commands such as ls, cd, cat, man, jobs, kill
void ProcessCommand(char command[32]);

//what the player does every update
void OnPlayerUpdate();

#endif