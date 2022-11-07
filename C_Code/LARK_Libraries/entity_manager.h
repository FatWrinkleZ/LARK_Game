#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include "Player.h"
#include "entity_functions.h"

enum TAGS{
    DEFAULT,
    PLAYER_TAG,
    PICKUP,
    DOOR,
    TRAP
};

extern char glyphText1[64];
extern char scrollText1[512];

extern Transform *ROOT;
extern Transform *entity1;
extern Transform *entity2;
extern Transform *entity3;
extern Transform *entity4;
extern Transform *trigger;
extern Transform *scroll1;
extern Transform *lantern;
extern Transform *chest;
extern Transform *glyph;

//logs all entities
void LOG_ENTITIES();

//sets up basic entities
void ENTITY_SETUP();

#endif