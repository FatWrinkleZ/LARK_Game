#ifndef PLAYER_H
#define PLAYER_H
#include "engine_man.h"
#include <dirent.h>
#include <stdbool.h>
#include "../MikeEngine/Engine.h"

extern int health;

extern float movementSpeed;
extern float rotateSpeed;

extern Transform *item;

//processes the ./ command
void dotSlashCmD(char command[64]);

//outputs all files in the LEVELS directory
void LS();

//processes commands such as ls, cd, cat, man, jobs, kill
void ProcessCommand(char command[32]);

//returns true if the given character classifies as a solid block
bool isASolidBlock(char c);

//what the player does every update
void OnPlayerUpdate(Transform* this);

#endif