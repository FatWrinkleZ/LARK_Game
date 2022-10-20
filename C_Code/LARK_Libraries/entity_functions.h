#ifndef ENTITY_FUNCTIONS_H
#define ENTITY_FUNCTIONS_H

#include "../MikeEngine/Engine.h"

//--------IMPORTANT INFO HERE => [if you want to add a function for an entity, you make the prototype function here and then implement in entity_functions.c] <= ----------//

//checks if the given transform.position matches the player transform.position. prints entity.name to terminal output
void TriggerUpdate(Transform* this);

//just sets the terminal output to the given string
void WriteToTerminalOutput(char* str);

//changes visibility of given transform to that of active bool
void SetActive(Transform* t, bool active);

#endif