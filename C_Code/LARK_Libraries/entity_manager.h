#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include "Player.h"
#include "entity_functions.h"

enum TAGS{
    DEFAULT,
    PLAYER_TAG,
    KEY,
    DOOR,
};

extern Transform *ROOT;
extern Transform *entity1;
extern Transform *entity2;
extern Transform *entity3;
extern Transform *entity4;
extern Transform *trigger;

//logs all entities
void LOG_ENTITIES();

//sets up basic entities
void ENTITY_SETUP();

#endif