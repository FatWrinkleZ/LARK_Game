#ifndef ENTITY_FUNCTIONS_H
#define ENTITY_FUNCTIONS_H
#include "../.MikeEngine/Engine.h"

//--------IMPORTANT INFO HERE => [if you want to add a function for an entity, you make the prototype function here and then implement in entity_functions.c] <= ----------//

//checks if the given transform.position matches the player transform.position. prints entity.name to terminal output
void TriggerUpdate(Transform* this);

//just sets the terminal output to the given string
void WriteToTerminalOutput(char* str);

//adds given string to the terminal output
void AddToTerminalOutput(char* str);

//changes visibility of given transform to that of active bool
void SetActive(Transform* t, bool active);

//highlights all nearby traps
void UseLantern(void);

//checks all surrounding tiles of the player to see if they are a compatible door
void UseKey(Transform *key);

//triggers trap and does damage if player walks over it
void TriggerTrap(Transform* this);

//Heals the player when they find and inspect a chest
void OpenChest(Transform *t);

//triggers a trap and then disables itself
void TriggerTrapOnce(Transform *t);

#endif